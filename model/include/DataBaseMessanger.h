#ifndef DATABASEMESSANGER_H_
#define DATABASEMESSANGER_H_

#include <vector>
#include <cstring>
#include <map>

class Message {
public:
    virtual int getId() = 0;
    virtual std::string getContent() = 0;
protected:
    int id_;
    std::string date_creating_;

};

class TextMessage :public Message {
public:
    TextMessage();
    TextMessage(int id, std::string content, std::string date);
    ~TextMessage();

    int getId() override;
    std::string getContent() override;
private:
    std::string text_content_;

};

class PictureMessage :public Message {
public:
    PictureMessage();
    PictureMessage(int id, std::string content, std::string date);
    ~PictureMessage();

    int getId() override;
    std::string getContent() override;
private:
    std::string picture_content_;

};

class Chat {
private:
    int chat_id_;
    std::string name_;
    std::vector<int> user_list_;
    std::vector<TextMessage> chat_t_massages_;
    std::vector<PictureMessage> chat_p_massages_;
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