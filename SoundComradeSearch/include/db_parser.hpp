#ifndef DB_PARSER_HPP
#define DB_PARSER_HPP

#include <abs_db_parser.hpp>

class DBParser : public AbsDBParser {
 public:
    ResponseFromDB Parse(const std::string &string) override;
};

#endif