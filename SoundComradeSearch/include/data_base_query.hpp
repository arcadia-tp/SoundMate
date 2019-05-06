#ifndef DB_QUERY_HPP
#define DB_QUERY_HPP


#include <vector>
#include <string>
#include <utility>
#include <memory>

#include <response_from_db.hpp>
#include <category.hpp>


class DataBaseQuery {
 public:
    DataBaseQuery();
    ResponseFromDB &GetResponse();
    int GetQuaryState();
    ~DataBaseQuery();
 private:
    int user_id_;
    int query_state_;
    ResponseFromDB response_;
    Category quary_;
};

typedef std::shared_ptr<DataBaseQuery> DBQueryPtr;

class DataBaseQueryStorage {
 public:
    DataBaseQueryStorage();
    ~DataBaseQueryStorage();
    void AddCategory(Category &);
    int GetQuaryState(const int);
    Category &GetCategory();
    ResponseFromDB &GetQuaryResponse(const int);
 private:
    std::vector<DBQueryPtr> storage_;
};

#endif