#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <map>
#include <string>
#include <utility>
#include <vector>

#include <category.hpp>
#include <data_base_query.hpp>
#include <query_processor.hpp>
#include <response_from_db.hpp>


namespace request_state {
   enum {READY_FOR_DB, READY_TO_PROCESS, OVER, READY_FOR_CLIENT, WAITING};
}

template <class UserContainer> class Request {
public:
  Request(ClientQuery &client_query, const int request_id);
  ~Request();
  int GetState() const;
  std::vector<UserData> &GetCategoryQuery();
  void CreateCategoryQuery();
  void Calculate();

private:
  int request_id_;
  ClientQuery client_query_;
  int state_;
  int category_to_process_;
  UserContainer users_priorities_;

  AbstractProcessor<UserContainer> *processor_;

  DataBaseQueryStorage *d_b_query_storage_;

private:
};


#endif