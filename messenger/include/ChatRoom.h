#ifndef SOUNDMATE_MESSENGER_CHATROOM_H
#define SOUNDMATE_MESSENGER_CHATROOM_H

#include <string>
#include <list>
#include "ChatUser.h"
#include "Message.h"

class ChatRoom
{
private:

    int chat_id;
    std::string chat_name;
    void SendHistoryToDB( );
    void GetHistoryFromDB();

public:
    ChatRoom();
    ~ChatRoom();
    void Join(ChatUser *user);
    void Leave(ChatUser *user);
    void Send(Message *msg);

};

ChatRoom::ChatRoom()
{
}

ChatRoom::~ChatRoom()
{
}


#endif