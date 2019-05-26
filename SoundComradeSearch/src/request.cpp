#include <request.hpp>
#include <query_processor.hpp>

typedef std::map<int, int> IntMap;

template <>
Request<IntMap>::Request(ClientQuery &client_query) : 
            category_to_process_(0), client_query_(client_query), request_id_(client_query.query_id) {};

template <>
Request<IntMap>::Request(ClientQuery &client_query, std::shared_ptr<AbstractProcessor<IntMap>> processor) : 
            category_to_process_(0), client_query_(client_query), processor_(processor), 
            users_priorities_(), request_id_(client_query.query_id) {
};

template <>
Request<IntMap>::~Request() {};

template <>
const IntMap &Request<IntMap>::GetUsers() {
    return users_priorities_;
}

template <>
int Request<IntMap>::GetRequestId() const {
    return request_id_;
}

template <>
void Request<IntMap>::Calculate(ResponseFromDB &response) {
    processor_->ProceedCategoryQuery(client_query_.request[category_to_process_],
                    response.response_vector, users_priorities_);

    if (category_to_process_ == client_query_.request.size() - 1) {
        state_ = request_state::READY_FOR_CLIENT;
    } else ++category_to_process_;
}

template <>
Category& Request<IntMap>::GetCategoryQuery() {
    return client_query_.request[category_to_process_];
};


template <>
int Request<IntMap>::GetRequestState() const {
    return state_;
};