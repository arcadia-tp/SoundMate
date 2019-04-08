#ifndef SERVER_HPP
#define SERVER_HPP

#include <client_connection.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>


typedef boost::shared_ptr<ClientConnection> ClientPtr;
typedef std::vector<ClientPtr> array;

class Server {
    int port_;
    array clients_;
    boost::thread_group threads_;
    HandleThreads *handle_threads_;
public:
    Server(HandleThreads *handle_threads, int port);
    void RunThreads();
};

class HandleThreads {
public:
    static void ClientsThreadHandle();
    static void SearchThreadHandle();
    static void DataBaseWriteThreadHandle();
    static void DataBaseReadThreadHandle();
    static void AcceptConnectionsThreadHandle();
};

class ClientAcceptor {
    static void FaitForClient();
};
#endif