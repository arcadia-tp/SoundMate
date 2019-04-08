#include "../include/test_cl_parser.hpp"

TEST(ClientRequestParser, ValidStrings) {
    AbstractParser parser;
    const char *message = "instrument: guitar | genre:  rock  pop jazz";
    typedef std::vector<std::pair<std::string, std::vector<std::string>>> request;
    
    std::string instrument = "instrument";
    std::string guitare = "guitare";
    std::vector guitare_vector{guitare,};

    request test_req{std::make_pair(instrument, guitare_vector), 
                     std::make_pair(std::string("genre"), std::vector
                     {std::string("rock"), std::string("pop"), std::string("jazz")})};

    EXPECT_EQ(test_req, parser.Parse(message, sizeof(message)));  

    //write more test cases for parser
}
