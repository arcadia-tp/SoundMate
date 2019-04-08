#include "../include/test_client_connection.hpp"

TEST(ClientConnectionTest, ValidStrings) {
    boost::asio::io_service service;
    AbstractParser parser; //use mock
    int user_id = 4;
    ClientConnection(user_id, service, &parser);
    // EXPECT_EQ(1, 2);
}
