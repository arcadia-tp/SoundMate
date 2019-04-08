#ifndef SOUNDMATE_MESSENGER_LOGGER_H
#define SOUNDMATE_MESSENGER_LOGGER_H

class AbstractLogger
{
private:
    
public:
    AbstractLogger();
    virtual ~AbstractLogger();
    virtual void Write();
};

AbstractLogger::AbstractLogger()
{
}

AbstractLogger::~AbstractLogger()
{
}



class TestLogger: public AbstractLogger
{
private:
    
public:
    TestLogger();
    ~TestLogger();
    void Write() override;
};

TestLogger::TestLogger()
{
}

TestLogger::~TestLogger()
{
}



#endif