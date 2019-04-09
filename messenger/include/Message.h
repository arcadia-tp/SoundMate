#ifndef SOUNDMATE_MESSENGER_MESSAGE_H
#define SOUNDMATE_MESSENGER_MESSAGE_H

#include <ctime>
#include <string>

class Message
{
private:
 
    int sender_id;
    time_t time_sent;

public:
    Message();
    ~Message();

    std::string content;

};

Message::Message()
{
}

Message::~Message()
{
}



#endif