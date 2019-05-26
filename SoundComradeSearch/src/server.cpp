#include <server.hpp>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/thread.hpp>
#include <memory>
#include <functional>

#include <request.hpp>
#include <category.hpp>
#include <client_connection.hpp>
#include <data_base_adapter.hpp>

#include <abs_query_processor.hpp>
#include <query_processor.hpp>
#include <db_parser.hpp>

typedef boost::asio::ip::tcp::socket BSocket;
typedef Request<std::map<int, int>> MapRequest;
typedef std::shared_ptr<AbstractConnection<BSocket, 
            ClientQuery>> ClientPtr;
typedef std::shared_ptr<MapRequest> RequestPtr;
typedef std::vector<ClientPtr> ClientsArray;


class ServerImpl : std::enable_shared_from_this<ServerImpl> {
 public:
    ServerImpl(std::string ip, uint port) : ip_(ip), port_(port) {
        DB_adapter.reset(new DataBaseAdapter<MapRequest>(service, new DBParser()));
    };
    void RunServer();
    ~ServerImpl() {};

 private:
    std::string ip_;
    int port_;
    std::shared_ptr<AbsDataBaseAdapter<MapRequest>> DB_adapter;
    boost::asio::io_service service;
    
 private:
    static void accept_thread(ServerImpl *server_impl, std::shared_ptr<AbsDataBaseAdapter<MapRequest>> &DB_adapter);
    static void handle_client_thread(ServerImpl *server_impl, std::shared_ptr<AbsDataBaseAdapter<MapRequest>> &DB_adapter,
                    ClientPtr &client_conn);
};

Server::Server(std::string ip, uint port) : server_impl_(new ServerImpl(ip, port)) {}
Server::~Server() {}

void Server::RunServer() {
    server_impl_->RunServer();
}

void ServerImpl::ServerImpl::RunServer() {
    boost::thread_group threads;
    threads.create_thread(std::bind(accept_thread, this, std::ref(DB_adapter)));
    threads.join_all();
}

void ServerImpl::accept_thread(ServerImpl *server_impl, 
        std::shared_ptr<AbsDataBaseAdapter<MapRequest>> &DB_adapter) {
    boost::thread_group l_threads;
    boost::asio::ip::tcp::acceptor acceptor(server_impl->service,
        boost::asio::ip::tcp::endpoint(
            boost::asio::ip::address::from_string(server_impl->ip_), server_impl->port_
        )
    );

    while (true) {
        ClientPtr new_conn_ptr(new ClientConnection<BSocket, ClientQuery>(server_impl->service));
        acceptor.accept(new_conn_ptr->Sock());

        l_threads.create_thread(std::bind(handle_client_thread, server_impl,
                std::ref(DB_adapter), std::move(new_conn_ptr)));
    }
    l_threads.join_all();
}


void ServerImpl::handle_client_thread(ServerImpl *server_impl, 
        std::shared_ptr<AbsDataBaseAdapter<MapRequest>> &DB_adapter, ClientPtr &client_conn) {
    
    while (client_conn->GetState() == READING) {
        client_conn->ReadRequest();
    }

    ClientQuery query_from_client = client_conn->Parse();

    std::shared_ptr<AbstractProcessor<UsersMap>> processor(new QueryProcessor());

    MapRequest request(query_from_client, processor);
    while(request.GetRequestState() != request_state::READY_FOR_CLIENT) {
        Category category_to_process = request.GetCategoryQuery();
        std::string str_to_process = request.GetCategoryQuery().CategoryToString();

        std::string id_string = "id: " + std::to_string(request.GetRequestId()) + " | ";
        str_to_process = id_string + str_to_process;

        ResponseFromDB response = DB_adapter->GetResponse(str_to_process);

        request.Calculate(response);
    }
    client_conn->SendDataToClient(request.GetUsers());
}
