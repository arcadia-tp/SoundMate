#ifndef QUERY_PROCESSOR_HPP
#define QUERY_PROCESSOR_HPP

#include <map>

#include <abs_query_processor.hpp>

typedef std::map<int, int> UsersMap;

class QueryProcessor : public AbstractProcessor<UsersMap> {
 public:
  void ProceedCategoryQuery(const Category &category,
                            const std::vector<UserData> &response_vector,
                            UsersMap &users_map);
};

#endif