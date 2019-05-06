#include <client_connection.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp>
#include <iostream>
#include <memory>

#include <request.hpp>
#include <client_connection.hpp>
#include <category.hpp>

typedef boost::asio::ip::tcp::socket BSocket;

template<>
class ClientConnectionImpl<BSocket, ClientQuery> {
 public:
    ClientConnectionImpl(boost::asio::io_service &service) : sock_(service), 
            already_read_(0), state_(READING) {
            
    }; //params
    void AnswerToClient();
    void StopConnection(){};
    void ReadRequest();
    void ProcessConnection();
    ClientQuery Parse();
    BSocket &Sock() { return sock_;}
    int GetState() const { return state_;};
    int GetConnectionID() { return user_id_;}

    ~ClientConnectionImpl(){};

 private:
    int state_;
    std::string ip_;
    int user_id_;
    BSocket sock_;
    int already_read_;
    enum { max_msg = 1024 };
    char message_buffer_[max_msg];
    std::string message_;
    AbstractParser *parser_;
 private:
};

template <>
ClientConnection<BSocket, ClientQuery >::ClientConnection(
                    boost::asio::io_service &service) :
    implementor_(new ClientConnectionImpl<BSocket, ClientQuery>(service)) {
}

template <>
void ClientConnection<BSocket, ClientQuery>::StopConnection() {
    implementor_->StopConnection();
}

template <>
void ClientConnection<BSocket, ClientQuery>::ReadRequest() {
    implementor_->ReadRequest();
}

template <>
void ClientConnection<BSocket, ClientQuery>::ProcessConnection() {
    implementor_->ProcessConnection();
}

template <>
void ClientConnection<BSocket, ClientQuery>::AnswerToClient() {
    implementor_->AnswerToClient();
}

template <>
int ClientConnection<BSocket, ClientQuery>::GetState() {
  return implementor_->GetState();
}

template <>
BSocket &ClientConnection<BSocket, ClientQuery>::Sock() {
  return implementor_->Sock();
}

template <>
ClientQuery ClientConnection<BSocket, ClientQuery>::Parse( ) {
    return implementor_->Parse();
}

template <>
ClientConnection<BSocket, ClientQuery>::~ClientConnection() {
    implementor_->~ClientConnectionImpl();
}

template <>
int ClientConnection<BSocket, ClientQuery>::GetConnectionID() {
    return implementor_->GetConnectionID();
}

void ClientConnectionImpl<BSocket, ClientQuery>::ProcessConnection() {

};


void ClientConnectionImpl<BSocket, ClientQuery>::ReadRequest() {
    if (sock_.available())
            already_read_ += sock_.read_some(
                boost::asio::buffer(message_buffer_ + already_read_, max_msg - already_read_));

    bool found_enter = std::find(message_buffer_, message_buffer_ + already_read_, '\n') 
                          < message_buffer_ + already_read_;
    if ( !found_enter)
        return;
    state_ = READY_FOR_CLIENT;
    size_t pos = std::find(message_buffer_, message_buffer_ + already_read_, '\n') - message_buffer_;
    message_ = std::string(message_buffer_, pos);
    std::cout << std::endl << "readed:" << message_ << std::endl;
    // std::copy(message_buffer_ + already_read_, message_buffer_ + max_msg, message_buffer_);
    // already_read_ -= pos + 1; //why
}

void ClientConnectionImpl<BSocket, ClientQuery>::AnswerToClient() {
    sock_.write_some(boost::asio::buffer(message_));
    state_ = OVER;
}

void StopConnection() {

}

ClientQuery ClientConnectionImpl<BSocket, ClientQuery>::Parse() {
    return parser_->Parse(message_);
}
