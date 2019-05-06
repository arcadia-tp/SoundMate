#include "DataBaseMessanger.h"


// Класс Chat *****************************

Chat::Chat(){}
Chat::~Chat(){}

void Chat::setName(std::string chat_name){
    name = chat_name;
}

void Chat::addUser(int id){
    user_list.push_back(id);
}

void Chat::addTextMessage(int id, std::string content, std::string date){
    TextMessage message(id, content, date);
    chat_t_massages.push_back(message);
}

void Chat::addPictureMessage(int id, std::string content, std::string date) {
    PictureMessage message(id, content, date);
    chat_p_massages.push_back(message);
}

int Chat::getId(){
    return chat_id;
}

std::string Chat::getName(){
    return name;
}

std::vector<int> Chat::getUserList(){
    return user_list;
}

TextMessage Chat::getTextMessage(int id_m){
    return chat_t_massages[id_m];
}

PictureMessage Chat::getPictureMessage(int id_m){
    return chat_p_massages[id_m];
}

// Класс TextMessage **********************

TextMessage::TextMessage(){}
TextMessage::TextMessage(int id_, std::string content, std::string date) {
    id = id_;
    text_content = content;
    date_creating = date;
}

TextMessage::~TextMessage(){}

int TextMessage::getId(){
    return id;
}

std::string TextMessage::getContent(){
    return text_content;
}

// Класс PictureMessage *******************

PictureMessage::PictureMessage(){}
PictureMessage::PictureMessage(int id_, std::string content, std::string date) {
    id = id_;
    picture_content = content;
    date_creating = date;
}

PictureMessage::~PictureMessage(){}

int PictureMessage::getId(){
    return id;
}

std::string PictureMessage::getContent(){
    return picture_content;
}


