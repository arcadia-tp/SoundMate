#ifndef DB_CONNECTION_HPP
#define DB_CONNECTION_HPP

#include <boost/asio/ip/tcp.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <memory>

#include <abs_db_parser.hpp>
#include <abs_data_base_adapter.hpp>

template  <class Request>
class DataBaseAdapter : public AbsDataBaseAdapter<Request> {
 public:
    DataBaseAdapter(boost::asio::io_service &service,
                                   AbsDBParser *parser);
    void StopConnection();
    ResponseFromDB GetResponse(const std::string &);
    ~DataBaseAdapter();
 private:
    boost::asio::ip::tcp::socket sock_;
    char message_buffer_[1024];
    std::shared_ptr<AbsDBParser> parser_;
};

#endif