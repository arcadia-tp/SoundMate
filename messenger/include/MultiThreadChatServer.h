#ifndef SOUNDMATE_MESSENGER_MULTITHREADCHATSERVER_H
#define SOUNDMATE_MESSENGER_MULTITHREADCHATSERVER_H


#include <boost/asio.hpp>

using boost::asio::ip::tcp;

typedef boost::shared_ptr<UserConnection> UserPtr;
typedef std::vector<UserPtr> array;


class MultiThreadChatServer
{
private:
    
    std::vector<UserPtr> users;
    boost::thread_group threads;

public:
    MultiThreadChatServer();
    ~MultiThreadChatServer();
    void RunThreads();
};

MultiThreadChatServer::MultiThreadChatServer()
{
}

MultiThreadChatServer::~MultiThreadChatServer()
{
}





class ThreadsHandler
{
private:
    
public:
    ThreadsHandler();
    ~ThreadsHandler();
    void DatabaseWriteThread();
    void DatabaseReadThread();
    void ChatRoomThread();
    void UserThread();
    void UserAcceptorThread();
};

ThreadsHandler::ThreadsHandler()
{
}

ThreadsHandler::~ThreadsHandler()
{
}



#endif