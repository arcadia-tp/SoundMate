#ifndef ABS_QUERY_PROCESSOR_HPP
#define ABS_QUERY_PROCESSOR_HPP


#include <response_from_db.hpp>
#include <category.hpp>

template <class UserContainer>
class AbstractProcessor {
public:
    virtual void ProceedCategoryQuery(const Category &,
        const std::vector<UserData> &, UserContainer &) = 0;
    virtual ~AbstractProcessor() {};
};


#endif