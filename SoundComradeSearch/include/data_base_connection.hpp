#ifndef DB_CONNECTION_HPP
#define DB_CONNECTION_HPP

#include <boost/asio/ip/tcp.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

#include <data_base_query.hpp>
#include <db_parser.hpp>
#include <memory>

class DataBaseConnection : std::enable_shared_from_this<DataBaseConnection> {
 public:
    DataBaseConnection(boost::asio::io_service &service,
                                   AbsDBParser *parser);
    void StopConnection();
    void ReadRequest();
    void ProcessRequest();
 private:
    boost::asio::ip::tcp::socket sock_; //remove from here to impl
    char *message_buffer_;
    AbsDBParser *parser_;
    boost::shared_ptr <DataBaseQueryStorage> query_storage_;
};

#endif