#ifndef DB_PARSER_HPP
#define DB_PARSER_HPP

#include <vector>
#include <string>
#include <utility>

typedef std::vector<std::pair<int, std::vector<std::string>>> ResponseFromDB;

typedef 
class DBParser {
public:
    virtual ResponseFromDB &Parse(const char*, size_t);
};

#endif