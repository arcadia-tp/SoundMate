#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>
#include <utility>


class AbstractParser {
 public:
    virtual std::vector<std::pair<std::string, std::vector<std::string>>>
    Parse(const char *string, size_t size);
};


#endif
