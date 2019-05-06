#include "../../include/db_parser.hpp"
#include "../../src/db_parser.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

using ::testing::AtLeast;
using ::testing::_;

using std::pair, std::string, std::vector, std::make_pair;

TEST(DataBaseParserTest, Args) {
    AbsDBParser *parser = new DBParser();
    std::string str1("id: 10 | 5 guitar  piano | 3 drum");

    ResponseFromDB response = parser->Parse(str1);
    EXPECT_EQ(10, response.request_owner_id);
    EXPECT_EQ(5, response.response_vector[0].user_id);
    EXPECT_EQ(3, response.response_vector[1].user_id);

    EXPECT_EQ("guitar", response.response_vector[0].data_vector[0]);
    EXPECT_EQ("piano", response.response_vector[0].data_vector[1]);
    EXPECT_EQ("drum", response.response_vector[1].data_vector[0]);

    std::string str2("id: 322 | 9 guitar  balalaika | 10000 drum piano | 29  bagpipe  cello drum  ");

    response = parser->Parse(str2);
    EXPECT_EQ(322, response.request_owner_id);
    EXPECT_EQ(9, response.response_vector[0].user_id);
    EXPECT_EQ(10000, response.response_vector[1].user_id);
    EXPECT_EQ(29, response.response_vector[2].user_id);

    EXPECT_EQ("guitar", response.response_vector[0].data_vector[0]);
    EXPECT_EQ("balalaika", response.response_vector[0].data_vector[1]);
    EXPECT_EQ("drum", response.response_vector[1].data_vector[0]);
    EXPECT_EQ("piano", response.response_vector[1].data_vector[1]);
    EXPECT_EQ("bagpipe", response.response_vector[2].data_vector[0]);
    EXPECT_EQ("cello", response.response_vector[2].data_vector[1]);
    EXPECT_EQ("drum", response.response_vector[2].data_vector[2]);

    std::string str3("id: 322 | 9 pop  jazz rap | 10000 rock reggae pop | 29  blues  ");

    response = parser->Parse(str3);
    EXPECT_EQ(322, response.request_owner_id);
    EXPECT_EQ(9, response.response_vector[0].user_id);
    EXPECT_EQ(10000, response.response_vector[1].user_id);
    EXPECT_EQ(29, response.response_vector[2].user_id);

    EXPECT_EQ("pop", response.response_vector[0].data_vector[0]);
    EXPECT_EQ("jazz", response.response_vector[0].data_vector[1]);
    EXPECT_EQ("rap", response.response_vector[0].data_vector[2]);
    EXPECT_EQ("rock", response.response_vector[1].data_vector[0]);
    EXPECT_EQ("reggae", response.response_vector[1].data_vector[1]);
    EXPECT_EQ("pop", response.response_vector[1].data_vector[2]);
    EXPECT_EQ("blues", response.response_vector[2].data_vector[0]);
}