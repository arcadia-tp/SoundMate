#ifndef USERACTIONFRAME_H_
#define USERACTIONFRAME_H_

#include <vector>
#include <cstring>
#include <map>

#include "DataBaseFrame.h"

class UserAction {
public:
    UserData* createUser();
    void changeMusicInstrument(UserData *User);
    void changeMusicGenre(UserData *User);
    void changeContactData(UserData *User);
    void createMessage(UserData *User1, UserData *User2);
    void login();
    void logout();
};

#endif // USERACTIONFRAME_H_