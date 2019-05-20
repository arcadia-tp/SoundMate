#include <server.hpp>
#include <iostream>

#include <mutex> //only one mutex
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
#include <search.hpp>
#include <data_base_connection.hpp>
#include <data_base_query.hpp>

typedef boost::asio::ip::tcp::socket BSocket; //2 typedefs
typedef Request<std::map<int, int>> MapRequest;
typedef std::shared_ptr<AbstractConnection<BSocket, 
            ClientQuery>> ClientPtr;
typedef std::shared_ptr<MapRequest> RequestPtr;
typedef std::vector<ClientPtr> ClientsArray;
typedef std::vector<RequestPtr> RequestArray;

//use git rm

class ServerImpl{
 public:
    ServerImpl(std::string ip, uint port) : ip_(ip), port_(port) {};
    void RunServer();
    ~ServerImpl(){};
 private:
    std::string ip_;
    int port_;
    ClientsArray clients_;
    boost::asio::io_service service;
    boost::recursive_mutex cs_;  //should switch on std::rec_mutex
    std::shared_ptr<Search<std::map<int, int>>> search_ptr_; //should pass storage_ptr into search
    std::shared_ptr<DataBaseQueryStorage> storage_ptr_;  
 private:
    static void accept_thread(ServerImpl* server_impl);
    static void handle_clients_thread(ServerImpl* server_impl, boost::thread_group &threads);
    static void search_thread(ServerImpl* server_impl, ClientQuery client_query, const int connection_id);
    void ProcessConnection();
};

Server::Server(std::string ip, uint port) : server_impl_(new ServerImpl(ip, port)) {} //make shared
Server::~Server() {server_impl_->~ServerImpl();}

void Server::RunServer() {
    server_impl_->RunServer();
}

void ServerImpl::ServerImpl::RunServer() {
    boost::thread_group threads;
    threads.create_thread(std::bind(accept_thread, this));
    threads.create_thread(std::bind(handle_clients_thread, this, std::ref(threads)));
    threads.join_all();
}

void ServerImpl::accept_thread(ServerImpl* server_impl) {
    boost::asio::ip::tcp::acceptor acceptor(server_impl->service,
        boost::asio::ip::tcp::endpoint(
        boost::asio::ip::address::from_string(server_impl->ip_), server_impl->port_
    ));

    while (true) {
        ClientPtr new_ptr(new ClientConnection<BSocket, ClientQuery>(server_impl->service));
        boost::this_thread::sleep_for(boost::chrono::milliseconds(2));
        std::cout << "waiting for clients\n";
        acceptor.accept(new_ptr->Sock());

        boost::recursive_mutex::scoped_lock lk(server_impl->cs_);

        bool flag = false;
        for (auto b = server_impl->clients_.begin(), e = server_impl->clients_.end(); b != e; ++b) {
            if ((*b)->GetState() == OVER) {
                (*b).~shared_ptr();
                *b = new_ptr;
                flag = true;
                std::cout << "shared_ptr is freed\n";
                break;
            }
        }
        if (!flag) server_impl->clients_.push_back(new_ptr);
    }
}

void ServerImpl::handle_clients_thread(ServerImpl* server_impl, boost::thread_group &threads) {
    
    while (true) {
        boost::this_thread::sleep_for(boost::chrono::milliseconds(2));
        boost::recursive_mutex::scoped_lock lk(server_impl->cs_);
        for (auto b = server_impl->clients_.begin(), e = server_impl->clients_.end(); b != e; ++b) {
            int state = (*b)->GetState();
            switch(state) {
                case READING: 
                    (*b)->ReadRequest();
                    continue;
                case READY_FOR_CLIENT:
                    (*b)->AnswerToClient();
                    continue;
                case READY_TO_PROCESS:
                    threads.create_thread(std::bind(search_thread, server_impl, (*b)->Parse(), (*b)->GetConnectionID()));
                    
                    continue;
                case WAITING:
                    continue;
                case OVER:
                    continue;
                default:
                    continue;
            }
        }
    }
}


void ServerImpl::search_thread(ServerImpl* server_impl, ClientQuery client_query, const int connection_id) {
    MapRequest(client_query, connection_id);

}

void ProcessConnection() {

}