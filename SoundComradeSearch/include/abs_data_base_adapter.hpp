#ifndef ABS_DB_CONNECTION_HPP
#define ABS_DB_CONNECTION_HPP

#include <memory>
#include <string>

template <class Request>
class AbsDataBaseAdapter : std::enable_shared_from_this<AbsDataBaseAdapter<Request>> {
 public:
    virtual ResponseFromDB GetResponse(const std::string &) = 0;
    virtual ~AbsDataBaseAdapter() {};
};

#endif