#ifndef SOUNDMATE_MODELS_H
#define SOUNDMATE_MODELS_H

#include <string>
#include <vector>
#include <memory>
#include "Utils.h"
#include "PresentEvents.h"

struct Permissions {
    Permissions() : viewPrivateData(false), viewSettings(false),
                    viewFriends(false), viewChats(false),
                    friendInviteAvailable(false), groupInviteAvailable(false),
                    sendMessageAvailable(false) {};
    ~Permissions() = default;
    bool viewPrivateData;
    bool viewSettings;
    bool viewFriends;
    bool viewChats;
    bool friendInviteAvailable;
    bool groupInviteAvailable;
    bool sendMessageAvailable;
};

struct FriendPermissions : public Permissions {
    FriendPermissions() {
        viewPrivateData = true;
        viewSettings = false;
        viewFriends = true;
        viewChats = false;
        friendInviteAvailable = false;
        groupInviteAvailable = true;
        sendMessageAvailable = true;
    };
    ~FriendPermissions() = default;
};

struct MyPermissions : public Permissions {
    MyPermissions() {
        viewPrivateData = true;
        viewSettings = true;
        viewFriends = true;
        viewChats = true;
        friendInviteAvailable = false;
        groupInviteAvailable = false;
        sendMessageAvailable = false;
    };
    ~MyPermissions() = default;
};

struct StrangerPermissions : public Permissions {
    StrangerPermissions() {
        viewPrivateData = false;
        viewSettings = false;
        viewFriends = false;
        viewChats = false;
        friendInviteAvailable = true;
        groupInviteAvailable = false;
        sendMessageAvailable = false;
    };
    ~StrangerPermissions() = default;
};
class IModel {
public:
    virtual ~IModel() = 0;
};

//IModel::~IModel() {};

class MainScreenModel : public IModel {
public:
    MainScreenModel() : IModel() {};
    ~MainScreenModel() override {};
    bool Autorization(std::string, std::string, int&);
    std::vector<std::shared_ptr<User>> GetRandom();
};

class RegisterScreenModel : public IModel {
public:
    RegisterScreenModel() : IModel() {};
    ~RegisterScreenModel() override {};
    bool FillingInfo(FieldEvent &);
    bool RegisterData(User_Data);

private:
    User_Data userInfo;
};

class IUserScreenModel : public IModel {
public:
    explicit IUserScreenModel(Permissions perms) : IModel(), permissions(perms) {};
    ~IUserScreenModel() override {};
    User_Data GetData(int);
    Permissions& GetPermissions();

protected:
    User_Data userinfo;
    Permissions permissions;
};

class StrangerUserScreenModel : public IUserScreenModel {
public:
    explicit StrangerUserScreenModel(StrangerPermissions perms) : IUserScreenModel(perms) {};
    ~StrangerUserScreenModel() override {};
    bool InviteToFriend(int);
};

class FriendUserScreenModel : public IUserScreenModel {
public:
    explicit FriendUserScreenModel(FriendPermissions perms) : IUserScreenModel(perms) {};
    ~FriendUserScreenModel() override {};
    bool SendMessage(std::string);
};

class MainUserScreenModel : public  IUserScreenModel {
public:
    explicit MainUserScreenModel(MyPermissions perms) : IUserScreenModel(perms) {};
    ~MainUserScreenModel() override {};
    bool ChangeData(User_Data&);
    bool GetFrineds();
    bool GetNews();
    bool GetEvents();
};

#endif //SOUNDMATE_MODELS_H
