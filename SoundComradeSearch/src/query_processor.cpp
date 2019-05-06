#include <map>

#include <query_processor.hpp>

typedef std::map<int, int> UsersMap;

class QueryProcessor : public AbstractProcessor<UsersMap> {
  void ProceedCategoryQuery(const Category &category,
                            const std::vector<UserData> &response_vector,
                            UsersMap &users_map) {
    for (auto user : response_vector) {
      auto current_user = users_map.find(user.user_id);
      for (auto key_word : category.key_words) {
        for (auto j : user.data_vector) {
          if (key_word == j) {
            current_user->second++;
            break;
          }
        }
      }
    }
  }
};

