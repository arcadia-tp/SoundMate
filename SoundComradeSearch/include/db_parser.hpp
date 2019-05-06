#ifndef DB_PARSER_HPP
#define DB_PARSER_HPP


#include <vector>
#include <string>
#include <utility>

#include <response_from_db.hpp>

class AbsDBParser {
public:
    virtual ResponseFromDB Parse(const std::string &) = 0;
    virtual ~AbsDBParser() {}
};

// AbsDBParser::~AbsDBParser() {};

#endif