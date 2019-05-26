#ifndef USERACTIONFRAME_H_
#define USERACTIONFRAME_H_

#include <vector>
#include <cstring>
#include <map>

#include "DataBasePerson.h"

class UserAction {
public:
    UserData* getUser(int id_user);
    void printUser(UserData *user);
    UserData* createUser();
    void changeInfo(UserData *user);
    void changeName(UserData *user);
    void changeSurname(UserData *user);
    void changeInformation(UserData *user);
    void changeAvatar(UserData *user);
    void changeContactData(UserData *user);
};

#endif // USERACTIONFRAME_H_