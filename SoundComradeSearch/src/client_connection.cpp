#include <boost/asio/ip/tcp.hpp>
#include <boost/chrono.hpp>
#include <boost/thread/thread.hpp>
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>

#include <request.hpp>
#include <client_connection.hpp>
#include <category.hpp>
#include <cl_parser.hpp>

typedef boost::asio::ip::tcp::socket BSocket;

template<>
class ClientConnectionImpl<BSocket, ClientQuery> {
 public:
    ClientConnectionImpl(boost::asio::io_service &service) : sock_(service), 
            already_read_(0), state_(READING) {
        parser_ = new ClientParser();
    };

    void AnswerToClient();
    void StopConnection();
    void ReadRequest();
    void ProcessConnection();
    void SendDataToClient(const std::map<int, int> &users);
    ClientQuery Parse();
    BSocket &Sock() { return sock_;}
    int GetState() const { return state_;};

    ~ClientConnectionImpl() {
        delete parser_;
    };

 private:
    int state_;
    std::string ip_;
    BSocket sock_;
    int already_read_;
    enum { MAX_MSG = 1024 };
    char message_buffer_[MAX_MSG];
    std::string message_;
    AbstractParser *parser_;
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
void ClientConnection<BSocket, ClientQuery>::SendDataToClient(const std::map<int, int> &users) {
    implementor_->SendDataToClient(users);
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
    delete implementor_;
}


void ClientConnectionImpl<BSocket, ClientQuery>::ProcessConnection() {

};


void ClientConnectionImpl<BSocket, ClientQuery>::ReadRequest() {
    if (sock_.available())
            already_read_ += sock_.read_some(
                boost::asio::buffer(message_buffer_ + already_read_, MAX_MSG - already_read_));

    bool found_enter = std::find(message_buffer_, message_buffer_ + already_read_, '\n') 
                          < message_buffer_ + already_read_;
    if (!found_enter)
        return;
    state_ = READY_TO_PROCESS;
    size_t pos = std::find(message_buffer_, message_buffer_ + already_read_, '\n') - message_buffer_;
    message_ = std::string(message_buffer_, pos);
}

void ClientConnectionImpl<BSocket, ClientQuery>::AnswerToClient() {
    std::cout << std::endl << "answer is " << message_ << std::endl;
    sock_.write_some(boost::asio::buffer(message_));
}

void ClientConnectionImpl<BSocket, ClientQuery>::StopConnection() {
    sock_.close();
}

ClientQuery ClientConnectionImpl<BSocket, ClientQuery>::Parse() {
    return parser_->Parse(message_);
}

void ClientConnectionImpl<BSocket, ClientQuery>::SendDataToClient(const std::map<int, int> &users) {
    std::vector <std::pair <int, int>> vec;
    for (auto i: users) {
        vec.push_back(i);
    }
    std::sort(vec.begin(), vec.end(), [](auto a, auto b){
        return a.second > b.second;
    });

    std::string result_string;
    for (auto i: vec) {
        result_string += ("id:" + std::to_string(i.first) + " rating: " + std::to_string(i.second) + " | ");
    }
    result_string += '\n';
    sock_.write_some(boost::asio::buffer(result_string));
    sock_.close(); //no
}
