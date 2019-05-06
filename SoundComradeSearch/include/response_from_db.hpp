#ifndef RESPONSE_FROM_DBB_HPP
#define RESPONSE_FROM_DBB_HPP

#include <vector>
#include <string>

struct UserData {
    int user_id;
    std::vector<std::string> data_vector; 
};

struct ResponseFromDB {
    int request_owner_id;
    std::vector<UserData> response_vector;
};

#endif