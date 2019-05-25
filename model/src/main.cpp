#include <iostream>

#include "UserActionFrame.h"
#include "SearchData.h"
#include <boost/lexical_cast.hpp>

enum Actions{EXIT_P, OPEN_PERSON, PRINT_PERSON, CREATE_PERSON, CHANGE_INFO, GET_ID_INSTR, GET_ID_GENRE}do_action;

void Menu();


int main() {
    bool go = true;
    int action = do_action;
    std::string str_search;

    UserData *db = NULL;
    UserAction user_action;

    while (go) {
        Menu();
        std::cin >> action;

        switch (action) {
        case EXIT_P:
            go = false;
            break;

        case OPEN_PERSON:
            std::cout << "Write user id:";
            int id_user;
            std::cin >> id_user;

            db = user_action.getUser(id_user);
            break;

        case PRINT_PERSON:
            user_action.printUser(db);
            break;

        case CREATE_PERSON:
            db = user_action.createUser();
            break;

        case CHANGE_INFO:
            user_action.changeInfo(db);
            break;

        case GET_ID_INSTR:
            //std::cin >> str_search;
            str_search = "id: 1 | instrument: guitar violin";
            std::cout << GetIdFromSearch(str_search, "instruments");
            break;

        case GET_ID_GENRE:
            //std::cin >> str_search;
            str_search = "id: 1 | genre: techno jazz";
            std::cout << GetIdFromSearch(str_search, "genres");
            break;

        default:
            std::cout << "Error action. Try again.\n";
            break;
        }
    }
    return 0;
}

void Menu() {
    std::cout << "\n" << EXIT_P << ": Exit\n" << OPEN_PERSON << ": Open person\n" << PRINT_PERSON
        << ": Print person\n" << CREATE_PERSON << ": Create person\n" << CHANGE_INFO << ": Change info\n"
        << GET_ID_INSTR << ": Search by instruments\n" << GET_ID_GENRE << ": Search by genres\n\n";
}