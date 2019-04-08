#ifndef SOUNDMATE_MESSENGER_DATABASE_H
#define SOUNDMATE_MESSENGER_DATABASE_H

#include "ChatRoom.h"
#include "ChatUser.h"
#include "Message.h"
#include <map>
#include <list>
#include <vector>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;



class Database
{
private:
    
    std::map<chat_id, std::list<Message>> ChatsHistory;
    std::map<user_id, std::vector<int>> UsersChatLists;
public:
    Database();
    ~Database();
};

Database::Database()
{
}

Database::~Database()
{
}





class DatabaseConnection
{
private:
    
public:
    DatabaseConnection();
    ~DatabaseConnection();
    void WriteChatHistory(int chat_id, std::list<Message> msg_history);
    void ReadChatHistory(int chat_id);
    void ReadChatList(int user_id);
};

DatabaseConnection::DatabaseConnection()
{
}

DatabaseConnection::~DatabaseConnection()
{
}




#endif