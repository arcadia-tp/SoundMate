#ifndef SERVER_HPP
#define SERVER_HPP

#include <abs_server.hpp>
#include <string>

class ServerImpl;

class Server : public AbstractServer {
 public:
    Server(std::string ip, uint port); //server impl by pointer
    void RunServer();
    ~Server();
 private:
    ServerImpl *server_impl_;
};


#endif