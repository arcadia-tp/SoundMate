#ifndef ABS_CONNECTION_HPP
#define ABS_CONNECTION_HPP

#include <memory>

template <class Socket, class Request>
class AbstractConnection : public std::enable_shared_from_this<AbstractConnection<Socket, Request>> {
 public:
    virtual void AnswerToClient() = 0;
    virtual void StopConnection() = 0;
    virtual void ReadRequest() = 0;
    virtual void ProcessConnection() = 0;
    virtual void SendDataToClient(const std::map<int, int> &) = 0; //map should be removed 
    virtual Socket &Sock() = 0;
    virtual int GetState() = 0;
    virtual Request Parse() = 0;
    virtual ~AbstractConnection() {};
};

#endif