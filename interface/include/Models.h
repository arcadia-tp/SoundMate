#ifndef SOUNDMATE_MODELS_H
#define SOUNDMATE_MODELS_H

#include <string>
#include <vector>
#include "Utils.h"

typedef struct permissions {
    bool viewPrivateData;
    bool viewSettings;
    bool viewFriends;
    bool viewChats;
    bool friendInviteAvailable;
    bool groupInviteAvailable;
    bool sendMessageAvailable;
} Permissions;

class IModel {
public:
    virtual ~IModel() = 0;
};

class MainScreenModel : public IModel {
public:
    MainScreenModel() : IModel() {};
    ~MainScreenModel() override;
    bool autorization(std::string, std::string, int&);
    std::vector<User *> getRandom();
};

class RegisterScreenModel : public IModel {
public:
    RegisterScreenModel() : IModel() {};
    ~RegisterScreenModel() override;
    bool fillingInfo(Field &);
    bool registerData(User_Data);

private:
    User_Data userInfo;
};

class IUserScreenModel : public IModel {
public:
    explicit IUserScreenModel(Permissions perms) : IModel(), permissions(perms) {};
    ~IUserScreenModel() override;
    User_Data getData(int);
    Permissions& getPermissions();

protected:
    User_Data userinfo;
    Permissions permissions;
};

class StrangerUserScreenModel : public IUserScreenModel {
public:
    explicit StrangerUserScreenModel(Permissions perms) : IUserScreenModel(perms) {};
    ~StrangerUserScreenModel() override;
    bool inviteToFriend(int);
};

class FriendUserScreenModel : public IUserScreenModel {
public:
    explicit FriendUserScreenModel(Permissions perms) : IUserScreenModel(perms) {};
    ~FriendUserScreenModel() override;
    bool sendMessage(std::string);
};

class MainUserScreenModel : public  IUserScreenModel {
public:
    explicit MainUserScreenModel(Permissions perms) : IUserScreenModel(perms) {};
    ~MainUserScreenModel() override;
    bool changeData(User_Data&);
    bool getFrineds();
    bool getNews();
    bool getEvents();
};

#endif //SOUNDMATE_MODELS_H
