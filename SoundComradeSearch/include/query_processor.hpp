#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <utility>
#include <vector>
#include <string>
#include <map>

typedef std::pair<std::string, std::vector<std::string>> UserCategoryRequest;
typedef std::vector<std::pair<int, std::vector<std::string>>>CategoryQuary;

class AbstractProcessor {
public:
    void ProceedCategoryQuary(const UserCategoryRequest &,
        const CategoryQuary &, std::map<int, int> &);
};

#endif