#ifndef CLIENT_CONNECTION_HPP
#define CLIENT_CONNECTION_HPP

#include <boost/asio.hpp>
#include <memory>

#include <abs_connection.hpp>
#include <cl_parser.hpp>

template <class Socket, class Request, class UserContainer>
class ClientConnectionImpl;

enum {READING, READY_TO_PROCESS};

template <class Socket, class Request, class UserContainer>
class ClientConnection : public AbstractConnection<Socket, Request, UserContainer> {
  public:
    ClientConnection(boost::asio::io_service &service);  //remove
    void AnswerToClient() override;
    void StopConnection() override;
    void ReadRequest() override;
    // void ProcessConnection() override;
    void SendDataToClient(const UserContainer &) override;
    Socket &Sock() override;
    int GetState() override;
    Request Parse() override;
    ~ClientConnection();
  private:
    ClientConnectionImpl<Socket, Request, UserContainer> *implementor_;
};

#endif