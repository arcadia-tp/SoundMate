#ifndef DB_CONNECTION_HPP
#define DB_CONNECTION_HPP

#include <boost/asio/ip/tcp.hpp>
#include <memory>

#include <abs_db_parser.hpp>
#include <abs_data_base_adapter.hpp>

template  <class Socket, class Request, class Service>
class DataBaseAdapter : public AbsDataBaseAdapter {
 public:
    DataBaseAdapter(Service &service, AbsDBParser *parser);
    void StopConnection();
    ResponseFromDB GetResponse(const std::string &);
    ~DataBaseAdapter();
 private:
    Socket sock_;
    char message_buffer_[1024];
    std::shared_ptr<AbsDBParser> parser_;
};

#endif