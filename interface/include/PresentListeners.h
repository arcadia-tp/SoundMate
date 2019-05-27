#ifndef SOUNDMATE_PRESENTLISTENERS_H
#define SOUNDMATE_PRESENTLISTENERS_H

#include "ViewObjects.h"
#include "PresentEvents.h"
#include <string>
#include <memory>
#include <vector>


//class IListener {
//public:
//    IListener() = default;
//    virtual ~IListener() = default;
//    inline virtual void add(std::shared_ptr<ViewObject>& obj) = 0;
//    virtual void updateExecute(std::string& info) = 0;
//    virtual void updateEvent(ViewObject& obj) = 0;
//    Как быть с тем, что нельзя возврашать объект абстракного класса? Можно указатель?
//    inline virtual ViewObject getEvent() = 0;
//protected:
//
//};

class ListenerButton {
public:
    ListenerButton() = default;
    ~ListenerButton() = default;
    explicit ListenerButton(std::vector<std::shared_ptr<Button>>& buts) : buttons(buts) {};
    inline void Add(std::shared_ptr<Button>& button) {
        buttons.emplace_back(button);
    }
//    virtual ~IListenerButton() = 0;

    bool CanHandle(Event& event);
    virtual bool UpdateExecute(IInteractNotify& info) {
        bool check = false;
        for (auto& button : buttons) {
            if (button->check(info)) {
                button->status = Button::EXEC;
                UpdateEvent(*button.get());
                check = true;
                break;
            } else {
                button->status = Button::NOT_EXEC;
            }
        }
        return check;
    }
    void UpdateEvent(Button& button) {
        event.type = button.type;
        event.status = button.status;
        event.referer = button.getReferer();
    }

    inline ButtonEvent getEvent() {
        ButtonEvent temp = event;
        // resetting
        event.type = Button::DEFAULT;
        return temp;
    }
private:
    ButtonEvent event;
    std::vector<std::shared_ptr<Button>> buttons;
};


class ListenerField {
public:
    ListenerField() = default;
    ~ListenerField() = default;
    explicit ListenerField(std::vector<std::shared_ptr<Field>>& flds) : fields(flds) {};
    inline void Add(std::shared_ptr<Field>& field) {
        fields.emplace_back(field);
    }

    bool CanHandle(Event& event);
    // TODO: Может быть несколько полей одновременно
    virtual void UpdateExecute(IInteractNotify& info) {
        for (auto& field : fields) {
            if (field->check(info)) {
                // TODO: ОБЩНОСТЬ + проверка
                field->input(std::cin);
                UpdateEvent(*field.get());
            } else {
                // NOTE: Черновой вариант
                field->clear();
            }
        }
    }
    void UpdateEvent(Field& field) {
        event.title = field.getTitle();
        event.state = field.state;
        event.data = field.getData();
    }
    inline FieldEvent getEvent() {
        FieldEvent temp = event;
        event.title = "undefined";
        return temp;
    }
private:
    FieldEvent event;
    std::vector<std::shared_ptr<Field>> fields;
};

#endif //SOUNDMATE_PRESENTLISTENERS_H
