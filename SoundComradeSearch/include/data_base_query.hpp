#ifndef DB_QUERY_HPP
#define DB_QUERY_HPP

#include <boost/shared_ptr.hpp>
#include <vector>
#include <string>
#include <utility>

typedef std::vector<std::pair<int, std::vector<std::string>>> ResponseFromDB;
typedef std::pair<std::string, std::vector<std::string>> CategoryQuery;

class DataBaseQuery {
    int user_id_;
    int query_state_;
    ResponseFromDB response_;
    CategoryQuery quary_;
public:
    DataBaseQuery();
    ResponseFromDB &GetResponse();
    int GetQuaryState();
    ~DataBaseQuery();
};

typedef boost::shared_ptr<DataBaseQuery> DBQueryPtr;

class DataBaseQueryStorage {
    std::vector<DBQueryPtr> storage_;
public:
    DataBaseQueryStorage();
    ~DataBaseQueryStorage();
    void AddQuery(CategoryQuery &);
    int GetQuaryState(const int);
    CategoryQuery &GetQuary();
    ResponseFromDB &GetQuaryResponse(const int);

};

#endif