#include "Presentors.h"


IPresent::~IPresent() {};
IPresentWithFields::~IPresentWithFields() {};

// Возможно, стоит прокидывать событие, чтобы переключаться или выходить
void MainScreenPresent::Update() {

    InteractNotify<std::string> notifyEvent;
    GetEntireEvents(notifyEvent);
    if (buttonsListener.UpdateExecute(notifyEvent)) {
        ButtonEvent butEvent = buttonsListener.getEvent();
        HandleEvent(butEvent);
    }
    if (fieldsListener.UpdateExecute(notifyEvent)) {
        FieldEvent fldEvent = fieldsListener.getEvent();
        HandleEvent(fldEvent);
    }
    std::cout << "ping" << std::endl;
//    switch (butEvent.type) {
//        case Button::Type::QUIT : {
//            break;
//        }
//        case Button::Type::SWITCH : {
//            break;
//        }
//        case Button::Type::BACK : {
//            break;
//        }
//        case Button::Type::COMMAND : {
//            FieldEvent fieldEvent = std::dynamic_pointer_cast<IViewWithFields>(currentView)->GetFieldEvent();
//        }
//        default: {
//            break;
//        }
//    }

    currentView->Show();
}
