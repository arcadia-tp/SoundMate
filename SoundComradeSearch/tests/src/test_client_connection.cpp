#include "../../include/client_connection.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::_;

TEST(ClientConnectionTest, ValidStrings) {
    boost::asio::io_service service;
    AbstractParser parser; //use mock
    int user_id = 4;
    ClientConnection(user_id, service, &parser);
}
