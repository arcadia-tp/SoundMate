#ifndef SEARCH_HPP
#define SEARCH_HPP


#include <boost/shared_ptr.hpp>
#include <vector>

#include <request.hpp>


typedef boost::shared_ptr<Request> RequestPtr;

class Search {
    std::vector<RequestPtr> request_vector_;
public:
    Search();
    void AcceptRequest();
    void RunSearch();
};

#endif