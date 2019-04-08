#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <vector>
#include <utility>
#include <map>
#include <query_processor.hpp>
#include <data_base_query.hpp>

using std::pair, std::string, std::vector;

enum {};

typedef vector<pair<string, vector<string>>> RequestVector;
typedef std::vector<std::pair<int, std::vector<std::string>>>CategoryQuery;

class Request {
private:
    int request_id_;
    RequestVector request_vec_;
    int request_state_;
    std::map<int, int> users_map_;
    AbstractProcessor *processor_;
    DataBaseQueryStorage *d_b_query_storage_;
public:
    Request();
    ~Request();
    void ProceedRequest();
private:
    void Calculate();
    void CreateCategoryQuery();
    CategoryQuery& GetCategoryQuery();
};
#endif
