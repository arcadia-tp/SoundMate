#include <client_connection.hpp>

ClientConnection::ClientConnection(int user_id, boost::asio::io_service &service, 
                    AbstractParser *parser) : sock_(service), parser_(parser) { }
void ClientConnection::StopConnection() {}
void ClientConnection::ReadRequest() {}
void ClientConnection::ProcessRequest() {}
void ClientConnection::AnswerToClient() {}