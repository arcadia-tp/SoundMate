#include <algorithm>
#include <iostream>

#include <strip_string.hpp>
#include <cl_parser.hpp>


const std::string kID = "id:";

class ClientParser : public AbstractParser {
 public:
    ClientQuery Parse(const std::string &string) override {
        ClientQuery query;

        std::cout << string << '\n';
        int begin = string.find(kID);
        std::cout << "begin is " << begin << '\n';

        int end = string.find("|", begin);
        std::cout << "end is " << end << '\n';

        std::string id_string = string.substr(begin + kID.size(), end - begin - kID.size());
        std::cout << "id_string is " << id_string << std::endl;

        std::string category;
        std::string key_word;
        std::string substring;
        while(true) {
            if (end == -1) break;
            Category category_object;
            begin = end + 1;
            end = string.find("|", begin);
            substring = string.substr(begin, end - begin);
            std::cout << "substring is " << substring << std::endl;
            
            bool first_word = true;
            int i = 0;
            for (; i < substring.size(); ++i) {
                if (isalpha(substring[i])) {
                    int j = i;
                    for (; j < substring.size(); ++j) {
                        if(isalpha(substring[j])) {
                            if (first_word) category.push_back(substring[j]);
                            else key_word.push_back(substring[j]);
                        } else break;
                    }
                    if (first_word) {
                        first_word = false;
                        std::cout << "category " << category << std::endl;
                        category_object.category_name = category;
                        category.clear();
                    } else {
                        std::cout << "key_word " << key_word << std::endl;
                        category_object.key_words.push_back(key_word);
                        key_word.clear();
                    }
                    i = j;
                }
            }
            query.request.push_back(category_object);
        }
        return query;
    }
};