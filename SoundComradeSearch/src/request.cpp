#include <request.hpp>

typedef std::map<int, int> IntMap;

template <>
Request<IntMap>::Request(ClientQuery &client_query, const int request_id) : category_to_process_(0), client_query_(client_query), request_id_(request_id) {};

template <>
Request<IntMap>::~Request() {};


template <>
void Request<IntMap>::Calculate() {
}

template <>
void Request<IntMap>::CreateCategoryQuery() {

};

template <class IntMap>
std::vector<UserData> &Request<IntMap>::GetCategoryQuery() {
    
};


template <>
int Request<IntMap>::GetState() const {
    return state_;
};