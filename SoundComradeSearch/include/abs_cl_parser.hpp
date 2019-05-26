#ifndef ABS_PARSER_HPP
#define ABS_PARSER_HPP

#include <string>
#include <category.hpp>

class AbstractParser {
 public:
    virtual ClientQuery Parse(const std::string &string) = 0;
    virtual ~AbstractParser() {};
};

#endif
