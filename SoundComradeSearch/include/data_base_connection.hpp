#ifndef DB_CONNECTION_HPP
#define DB_CONNECTION_HPP

#include <boost/asio/ip/tcp.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

#include <data_base_query.hpp>
#include <db_parser.hpp>

class DataBaseConnection : boost::enable_shared_from_this<DataBaseConnection> {
    boost::asio::ip::tcp::socket sock_;
    char *message_buffer_;
    DBParser *parser_;
    boost::shared_ptr <DataBaseQueryStorage> query_storage_;
 public:
    DataBaseConnection(boost::asio::io_service &service,
                                   DBParser *parser);
    void StopConnection();
    void ReadRequest();
    void ProcessRequest();
};

#endif