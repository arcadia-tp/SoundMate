#include <iostream>

#include "UserActionFrame.h"

void Menu();


int main() {
    bool go = true;
    int action;

    UserData *db = NULL;
    UserAction user_action;

    while (go) {
        Menu();
        std::cin >> action;

        switch (action) {
        case 0:
            go = false;
            break;

        case 1:
            std::cout << "Write user id:";
            int id_user;
            std::cin >> id_user;

            db = user_action.getUser(id_user);
            break;

        case 2:
            user_action.printUser(db);
            break;

        case 3:
            db = user_action.createUser();
            break;

        case 4:
            user_action.changeInfo(db);
            break;

        default:
            std::cout << "Error action. Try again.\n";
            break;
        }
    }
    return 0;
}

void Menu() {
    std::cout << "\n0: Exit\n1: Open person\n2: Print person\n3: Create person\n4: Change info\n\n";
}