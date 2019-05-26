#ifndef CLIENT_CONNECTION_HPP
#define CLIENT_CONNECTION_HPP

#include <boost/asio.hpp>
#include <memory>

#include <abs_connection.hpp>
#include <cl_parser.hpp>

template <class Socket, class Request>
class ClientConnectionImpl;

enum {READING, READY_TO_PROCESS};

template <class Socket, class Request>
class ClientConnection : public AbstractConnection<Socket, Request> {
  public:
    ClientConnection(boost::asio::io_service &service);  //remove
    void AnswerToClient() override;
    void StopConnection() override;
    void ReadRequest() override;
    void ProcessConnection() override;
    void SendDataToClient(const std::map<int, int> &) override;
    Socket &Sock() override;
    int GetState() override;
    Request Parse() override;
    ~ClientConnection();
  private:
    ClientConnectionImpl<Socket, Request> *implementor_;
};

#endif