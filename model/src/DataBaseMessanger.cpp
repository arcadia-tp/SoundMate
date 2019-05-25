#include "DataBaseMessanger.h"


// Класс Chat *****************************

Chat::Chat(){}
Chat::~Chat(){}

void Chat::setName(std::string chat_name){
    name_ = chat_name;
}

void Chat::addUser(int id){
    user_list_.push_back(id);
}

void Chat::addTextMessage(int id, std::string content, std::string date){
    TextMessage message(id, content, date);
    chat_t_massages_.push_back(message);
}

void Chat::addPictureMessage(int id, std::string content, std::string date) {
    PictureMessage message(id, content, date);
    chat_p_massages_.push_back(message);
}

int Chat::getId(){
    return chat_id_;
}

std::string Chat::getName(){
    return name_;
}

std::vector<int> Chat::getUserList(){
    return user_list_;
}

TextMessage Chat::getTextMessage(int id_m){
    return chat_t_massages_[id_m];
}

PictureMessage Chat::getPictureMessage(int id_m){
    return chat_p_massages_[id_m];
}

// Класс TextMessage **********************

TextMessage::TextMessage(){}
TextMessage::TextMessage(int id, std::string content, std::string date) {
    id_ = id;
    text_content_ = content;
    date_creating_ = date;
}

TextMessage::~TextMessage(){}

int TextMessage::getId(){
    return id_;
}

std::string TextMessage::getContent(){
    return text_content_;
}

// Класс PictureMessage *******************

PictureMessage::PictureMessage(){}
PictureMessage::PictureMessage(int id, std::string content, std::string date) {
    id_ = id;
    picture_content_ = content;
    date_creating_ = date;
}

PictureMessage::~PictureMessage(){}

int PictureMessage::getId(){
    return id_;
}

std::string PictureMessage::getContent(){
    return picture_content_;
}


