#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <memory>
#include <vector>

#include <request.hpp>

// template <class UserContainer>
// typedef std::shared_ptr<Request<UserContainer>> RequestPtr;


template <class UserContainer>
class Search {
public:
  Search();
  void AcceptRequest();
  void RunSearch();

private:
  typedef std::shared_ptr<Request<UserContainer>> RequestPtr;
  std::vector<RequestPtr> request_vector_;
};

#endif