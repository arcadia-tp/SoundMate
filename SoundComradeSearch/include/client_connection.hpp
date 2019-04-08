#ifndef CLIENT_CONNECTION_HPP
#define CLIENT_CONNECTION_HPP

#include <boost/asio/ip/tcp.hpp>
#include <cl_parser.hpp>
#include <boost/enable_shared_from_this.hpp>

class ClientConnection : public boost::enable_shared_from_this<ClientConnection> {
    int user_id_;
    boost::asio::ip::tcp::socket sock_;
    int already_read_;
    char *message_buffer_;
    AbstractParser *parser_;

 public:
    ClientConnection(int user_id, boost::asio::io_service &service, AbstractParser *parser); //params
    void AnswerToClient();
    void StopConnection();
    void ReadRequest();
    void ProcessRequest();
};

#endif