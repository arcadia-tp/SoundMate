#include <cl_parser.hpp>

const std::string kID = "id:";

ClientQuery ClientParser::Parse(const std::string &string) {
    ClientQuery query;

    int begin = string.find(kID);
    int end = string.find("|", begin);

    std::string id_string = string.substr(begin + kID.size(), end - begin - kID.size());    
    query.query_id = std::stoi(id_string);

    std::string category;
    std::string key_word;
    std::string substring;
    while(end != -1) {
        Category category_object;
        begin = end + 1;
        end = string.find("|", begin);
        substring = string.substr(begin, end - begin);
        
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
                    category_object.category_name = category;
                    category.clear();
                } else {
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