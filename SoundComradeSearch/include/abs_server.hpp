#ifndef ABSTRACT_SERVER_HPP
#define ABSTRACT_SERVER_HPP

class AbstractServer {
 public:
    void virtual RunServer() = 0;
    virtual ~AbstractServer() {};
};

#endif