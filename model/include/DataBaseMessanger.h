#ifndef DATABASEMESSANGER_H_
#define DATABASEMESSANGER_H_

#include <vector>
#include <cstring>
#include <map>

class Message {
protected:
    int id;
    std::string date_creating;
public:
    virtual int getId() = 0;
    virtual std::string getContent() = 0;
};

class TextMessage :public Message {
private:
    std::string text_content;
public:
    TextMessage();
    TextMessage(int id_, std::string content, std::string date);
    ~TextMessage();

    int getId() override;
    std::string getContent() override;
};

class PictureMessage :public Message {
private:
    std::string picture_content;
public:
    PictureMessage();
    PictureMessage(int id_, std::string content, std::string date);
    ~PictureMessage();

    int getId() override;
    std::string getContent() override;
};

class Chat {
private:
    int chat_id;
    std::string name;
    std::vector<int> user_list;
    std::vector<TextMessage> chat_t_massages;
    std::vector<PictureMessage> chat_p_massages;
public:
    Chat();
    ~Chat();

    void setName(std::string chat_name);
    void addUser(int id);
    void addTextMessage(int id, std::string content, std::string date);
    void addPictureMessage(int id, std::string content, std::string date);
    int getId();
    std::string getName();
    std::vector<int> getUserList();
    TextMessage getTextMessage(int id_m);
    PictureMessage getPictureMessage(int id_m);
};

#endif // DATABASEMESSANGER_H_