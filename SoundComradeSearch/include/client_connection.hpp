#ifndef CLIENT_CONNECTION_HPP
#define CLIENT_CONNECTION_HPP

#include <cl_parser.hpp>
#include <memory>
#include <abs_connection.hpp>
#include <boost/asio.hpp>

template <class Socket, class Request>
class ClientConnectionImpl;

enum {READING, READY_TO_PROCESS, OVER, READY_FOR_CLIENT, WAITING};

template <class Socket, class Request>
class ClientConnection : public AbstractConnection<Socket, Request> {
  public:
    ClientConnection(boost::asio::io_service &service); //params
    void AnswerToClient() override;
    void StopConnection() override;
    void ReadRequest() override;
    void ProcessConnection() override;
    Socket &Sock() override;
    int GetState() override;
    int GetConnectionID() override;
    Request Parse() override;
    ~ClientConnection();
  private:
    ClientConnectionImpl<Socket, Request> *implementor_;
};

#endif