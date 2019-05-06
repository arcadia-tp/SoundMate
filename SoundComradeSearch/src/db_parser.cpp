#include <algorithm>
#include <iostream>

#include <strip_string.hpp>
#include <db_parser.hpp>

const std::string kID = "id:";

class DBParser : public AbsDBParser {
 public:
    ResponseFromDB Parse(const std::string &string) override {
        ResponseFromDB response;

        std::cout << string << '\n';
        int begin = string.find(kID);

        int end = string.find("|", begin);

        std::string id_string = string.substr(begin + kID.size(), end - begin - kID.size());
        std::cout << "id_string is " << id_string << std::endl;

        response.request_owner_id = stoi(id_string);

        id_string.clear();
        std::string key_word;
        std::string substring;
        while(true) {
            if (end == -1) break;
            UserData user_data_object;
            begin = end + 1;
            end = string.find("|", begin);
            substring = string.substr(begin, end - begin);
            
            bool first_word = true;
            int i = 0;
            for (; i < substring.size(); ++i) {
                if (isalnum(substring[i])) {
                    int j = i;
                    for (; j < substring.size(); ++j) {
                        if(isalnum(substring[j])) {
                            if (first_word) id_string.push_back(substring[j]);
                            else key_word.push_back(substring[j]);
                        } else break;
                    }
                    if (first_word) {
                        first_word = false;
                        std::cout << "id_string " << id_string << std::endl;
                        user_data_object.user_id = stoi(id_string);
                        id_string.clear();
                    } else {
                        std::cout << "key_word " << key_word << std::endl;
                        user_data_object.data_vector.push_back(key_word);
                        key_word.clear();
                    }
                    i = j;
                }
            }
            response.response_vector.push_back(user_data_object);
        }
        return response;
    }
};