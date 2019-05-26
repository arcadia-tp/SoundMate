#ifndef PARSER_HPP
#define PARSER_HPP

#include <abs_cl_parser.hpp>

class ClientParser : public AbstractParser {
 public:
    ClientQuery Parse(const std::string &string) override;
};

#endif