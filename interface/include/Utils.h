#ifndef SOUNDMATE_UTILS_H
#define SOUNDMATE_UTILS_H

#include <vector>
#include <string>


typedef struct filter {
    std::vector<std::string> genres;
    std::vector<std::string> instruments;
    std::string geolocation;
} Filter;

class Field {
public:
    Field();
    ~Field();
    std::string info;
    std::string data;
};

class Chat {

};

class User {

};

class Event {

};

class ButtonEvent {

};

class ViewObject {

};

class Button {

};

class Message {

};

class User_Data {

};

#endif //SOUNDMATE_UTILS_H
