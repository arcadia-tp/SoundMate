#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

#include <category.hpp>

class AbstractParser {
 public:
    virtual ClientQuery Parse(const std::string &string) = 0;
    virtual ~AbstractParser() {};
};

// AbstractParser::~AbstractParser() {}

#endif
