#ifndef CATEGORY_HPP
#define CATEGORY_HPP

#include <vector>
#include <string>

struct Category {
    std::string category_name;
    std::vector<std::string> key_words;
};

struct ClientQuery {
    std::vector<Category> request;
};

#endif

