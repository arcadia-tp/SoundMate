#ifndef SOUNDMATE_MESSENGER_CHATUSER_H
#define SOUNDMATE_MESSENGER_CHATUSER_H

#include <string>
#include <vector>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class ChatUser
{
private:

    int user_id;
    std::string user_name;
    std::vector<int> ChatList;

public:
    ChatUser();
    ~ChatUser();
    void GetChatList();
};

ChatUser::ChatUser()
{
}

ChatUser::~ChatUser()
{
}



class UserConnection
{
private:
    

public:

    void StartConnection();
    void StopConnection();

    UserConnection();
    ~UserConnection();
};

UserConnection::UserConnection()
{
}

UserConnection::~UserConnection()
{
}



#endif