#ifndef SERVER_HPP
#define SERVER_HPP

#include <memory>
#include <string>

#include <abs_server.hpp>

class ServerImpl;

class Server : public AbstractServer {
 public:
    Server(std::string ip, uint port);
    void RunServer();
    ~Server();
 private:
    std::shared_ptr<ServerImpl> server_impl_;
};


#endif