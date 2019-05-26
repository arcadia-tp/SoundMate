#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <map>
#include <string>
#include <utility>
#include <vector>
#include <memory>

#include <category.hpp>
#include <query_processor.hpp>
#include <response_from_db.hpp>


namespace request_state {
   enum {READY_FOR_DB, READY_TO_PROCESS, OVER, READY_FOR_CLIENT, WAITING};
}

template <class UserContainer> 
class Request {
public:
  Request(ClientQuery &client_query);
  Request(ClientQuery &client_query, std::shared_ptr<AbstractProcessor<UserContainer>> processor);
  ~Request();

  int GetRequestState() const;
  Category& GetCategoryQuery();
  void Calculate(ResponseFromDB &);
  const UserContainer &GetUsers();
  int GetRequestId() const;

private:
  int request_id_;
  ClientQuery client_query_;
  int state_;
  int category_to_process_;
  UserContainer users_priorities_;

  std::shared_ptr <AbstractProcessor<UserContainer>> processor_;
};


#endif