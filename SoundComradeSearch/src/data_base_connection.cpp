#include <data_base_connection.hpp>

DataBaseConnection::DataBaseConnection(boost::asio::io_service &service,
                                   DBParser *parser) : sock_(service), parser_(parser) {}
void DataBaseConnection::StopConnection() {}
void DataBaseConnection::ReadRequest() {}
void DataBaseConnection::ProcessRequest() {}