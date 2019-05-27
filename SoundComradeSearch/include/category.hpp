#ifndef CATEGORY_HPP
#define CATEGORY_HPP

#include <vector>
#include <string>

struct Category {
    std::string category_name;
    std::vector<std::string> key_words;
    std::string CategoryToString() {
        std::string result;
        result = category_name + ": ";
        for (auto i: key_words) {
            result += (i + " ");
        }
        return result;
    }
};

struct ClientQuery {
    int query_id;
    std::vector<Category> request;
};

#endif

