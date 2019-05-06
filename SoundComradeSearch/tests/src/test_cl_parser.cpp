#include "../../include/cl_parser.hpp"
#include "../../src/cl_parser.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::AtLeast;
using ::testing::_;

using std::pair, std::string, std::vector, std::make_pair;

std::string *parse(std::string &string);

TEST(ClientRequestParser, ValidStrings) {
    AbstractParser *parser = new ClientParser();
    
    std::string str1("id: 22 | instrument: guitar | genre:  rock  pop jazz");
    
    ClientQuery query =  parser->Parse(str1);
    EXPECT_EQ("instrument", query.request[0].category_name);
    EXPECT_EQ("guitar", query.request[0].key_words[0]);

    EXPECT_EQ("genre", query.request[1].category_name);
    EXPECT_EQ("rock", query.request[1].key_words[0]);
    EXPECT_EQ("pop", query.request[1].key_words[1]);
    EXPECT_EQ("jazz", query.request[1].key_words[2]);

    std::string str2("id: 222 | instrument: balalaika flute | genre: folk");

    query = parser->Parse(str2);

    EXPECT_EQ("instrument", query.request[0].category_name);
    EXPECT_EQ("balalaika", query.request[0].key_words[0]);
    EXPECT_EQ("flute", query.request[0].key_words[1]);

    EXPECT_EQ("genre", query.request[1].category_name);
    EXPECT_EQ("folk", query.request[1].key_words[0]);
}

void StripString(std::string &mystr) {
    size_t index = 0;
    while((index = mystr.find(' '))!=std::string::npos)
        mystr.erase(index, 1);
}