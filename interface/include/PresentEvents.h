#ifndef SOUNDMATE_PRESENTEVENTS_H
#define SOUNDMATE_PRESENTEVENTS_H

#include <string>
#include <memory>
#include "ViewObjects.h"


//struct IEntireEvent {
//    std::string info;
//};

struct Event {
public:
    enum EventType {
        Closed, KeyPressed, ButtonExec, FieldExec
    };

    explicit Event(EventType _type) : type(_type) {};
//    Event(EventType _type, FieldEvent&  kindEvent) : type(_type), kind(kindEvent) {};
//    Event(EventType _type, KeyEvent& kindEvent) : type(_type), kind(kindEvent) {};

    EventType type;

//    const ButtonEvent& button() const {
//        return kind.button;
//    }
//    const FieldEvent& field() const {
//        return kind.field;
//    }
//    const KeyEvent& key() const {
//        return kind.key;
//    }
};

struct ButtonEvent : Event {
    explicit ButtonEvent(Button::Type type = Button::DEFAULT, Button::Status status = Button::NOT_EXEC,
                         std::string ref = std::string("None"))
            : Event(Event::ButtonExec), type(type), status(status), referer(std::move(ref)) {};
    ~ButtonEvent() = default;
    Button::Type type;
    Button::Status status;
    std::string referer;
};


struct FieldEvent : Event {
    explicit FieldEvent(Field::States state = Field::EMPTY, std::string title = std::string("None"),
                        std::string data = std::string())
            : Event(Event::FieldExec), state(state), title(std::move(title)), data(std::move(data)) {};
    Field::States state;
    std::string title;
    std::string data;
};


#endif //SOUNDMATE_PRESENTEVENTS_H
