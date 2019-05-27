#ifndef QUERY_PROCESSOR_HPP
#define QUERY_PROCESSOR_HPP

#include <abs_query_processor.hpp>

// typedef std::map<int, int> UsersMap;

template <class UserContainer>
class QueryProcessor : public AbstractProcessor<UserContainer> {
 public:
  void ProceedCategoryQuery(const Category &category,
                            const std::vector<UserData> &response_vector,
                            UserContainer &users_map);
};

#endif