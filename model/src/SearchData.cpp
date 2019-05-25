#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

#include "SearchData.h"
#include <boost/lexical_cast.hpp>

#define DEVISION 2

std::vector<std::string> Parser(std::string str) {
    std::vector<std::string> return_vector;
    std::istringstream in(str);
    std::string substr;
    in >> substr >> substr >> substr >> substr;
    while (in >> substr) {
        return_vector.push_back(substr);
    }
    return return_vector;
}

std::vector<std::string> GetInstrumentsFromStr(std::string str) {
    std::vector<std::string> return_vector;
    std::istringstream in(str);
    std::string substr;

    while (substr != "|") {
        in >> substr;
    }
    substr = "";
    while (substr != "|") {
        in >> substr;
        return_vector.push_back(substr);
    }
    return_vector.pop_back();
    return return_vector;
}

std::vector<std::string> GetGenresFromStr(std::string str) {
    std::vector<std::string> return_vector;
    std::istringstream in(str);
    std::string substr;
    int vert_count = 0;

    while (vert_count != DEVISION) {
        in >> substr;
        if (substr == "|") vert_count++;
    }
    substr = "";
    while (in >> substr) {
        return_vector.push_back(substr);
    }
    return return_vector;
}

std::string GetIdFromSearch(std::string str_search, std::string type_search) {
    std::string str, return_str = "";

    std::istringstream in(str_search);
    std::string substr;
    in >> substr;
    return_str += substr + " ";
    in >> substr;
    return_str += substr;


    std::string filename = "DB\\", f;

    std::ifstream F_PERSON;
    f = filename + "person.txt";
    F_PERSON.open(f);

    if (!F_PERSON.is_open()) {
        std::cout << "\nERR READING FILE" << std::endl;
        return return_str;
    }

    std::getline(F_PERSON, str);

    if ((boost::lexical_cast<int> (str)) == 0) {
        std::cout << "\nNO DATA" << std::endl;
        return return_str;;
    }

    std::vector<std::string> search_instr = Parser(str_search);

    while (!F_PERSON.eof()) {
        std::getline(F_PERSON, str);
        std::string str_id;

        std::istringstream(str) >> str_id;
        std::vector<std::string> file_data;

        if (type_search == "instruments") {
           file_data = GetInstrumentsFromStr(str);
        }
        else if (type_search == "genres") {
            file_data = GetGenresFromStr(str);
        }

        for (int i = 0; i < file_data.size(); i++) {
            auto result = std::find(search_instr.begin(), search_instr.end(), file_data[i]);
            if (result != search_instr.end()) {
                return_str += " | " + str_id;
                for (std::vector<std::string>::iterator it = file_data.begin(); it != file_data.end(); it++) {
                    return_str += " " + *it;
                }
                break;
            }
        }
    }

    F_PERSON.close();

    return return_str;
}
