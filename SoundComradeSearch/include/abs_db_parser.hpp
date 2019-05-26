#ifndef ABS_DB_PARSER_HPP
#define ABS_DB_PARSER_HPP

#include <response_from_db.hpp>

class AbsDBParser {
public:
    virtual ResponseFromDB Parse(const std::string &) = 0;
    virtual ~AbsDBParser() {}
};

#endif