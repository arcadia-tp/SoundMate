#ifndef SOUNDMATE_PRESENTORS_H
#define SOUNDMATE_PRESENTORS_H

#include <vector>
#include <queue>
#include <memory>
#include "Views.h"
#include "Models.h"
#include "PresentEvents.h"

class IPresent {
public:
    IPresent(std::shared_ptr<IView> _view, std::shared_ptr<IModel>& _model) : model(_model), currentView(_view) {
        views.push_back(currentView);
    }
    virtual ~IPresent() = 0;
    virtual void ChangeView() = 0;
    virtual void Update() = 0;
    virtual void HandleEvent(Event&) {}
    virtual void GetEntireEvents(IInteractNotify& event);
    virtual void HandleButton(ButtonEvent&) = 0;
//    virtual void HandleFields(FieldEvent&) = 0;
protected:
    std::shared_ptr<IModel> model;
    std::vector<std::shared_ptr<IView>> views;
    std::shared_ptr<IView> currentView;
    // очередь событий
    std::queue<Event> events;
    ListenerButton buttonsListener;
};

//void IPresent::HandleButton(ButtonEvent& event) {
//}

//IPresent::~IPresent() = default;

class IPresentWithFields : public IPresent {
public:
    IPresentWithFields(std::shared_ptr<IViewWithFields> _view, std::shared_ptr<IModel>& _model)
            : IPresent(std::dynamic_pointer_cast<IView>(_view), _model) {};
    virtual ~IPresentWithFields() = 0;
    virtual void HandleFields(FieldEvent&) = 0;

protected:
    ListenerField fieldsListener;
};

//IPresentWithFields::~IPresentWithFields() {};

class MainScreenPresent : public IPresentWithFields {
public:
    MainScreenPresent(std::shared_ptr<IViewWithFields> _view, std::shared_ptr<IModel> _model) : IPresentWithFields(_view, _model) {};
    ~MainScreenPresent() override {};
    void ChangeView() override {};
    void HandleButton(ButtonEvent &) override {};
    void HandleFields(FieldEvent&) override {};
    void Update() override;
};

class RegisterScreenPresent : public IPresentWithFields {
public:
    RegisterScreenPresent(std::shared_ptr<IViewWithFields> _view, std::shared_ptr<IModel> _model) : IPresentWithFields(_view, _model) {};
    ~RegisterScreenPresent() override {};
    void ChangeView() override {};
    void HandleButton(ButtonEvent &) override {};
    void HandleFields(FieldEvent &) override {};
    void Update() override {};
};

class UserScreenPresent : public IPresentWithFields {
public:
    UserScreenPresent(std::shared_ptr<IViewWithFields> _view, std::shared_ptr<IModel> _model) : IPresentWithFields(_view, _model) {};
    ~UserScreenPresent() override {};
    void ChangeView() override {};
    void HandleButton(ButtonEvent &) override {};
    void HandleFields(FieldEvent &) override {};
    void Update() override {};

private:
    std::vector<std::shared_ptr<User>> friends;
};

class MessengerScreenPresent : public IPresentWithFields {
public:
    MessengerScreenPresent(std::shared_ptr<IViewWithFields> _view, std::shared_ptr<IModel> _model) : IPresentWithFields(_view, _model) {};
    ~MessengerScreenPresent() override {};
    void ChangeView() override {};
    void HandleButton(ButtonEvent &) override {};
    void HandleFields(FieldEvent &) override;
    void GetChats();
    void Update() override {};

private:
    std::vector<std::shared_ptr<Chat>> chats;
    std::vector<std::shared_ptr<Message>> messages;
};

class SearchPresent : public IPresent {
public:
    SearchPresent(std::shared_ptr<IView> _view, std::shared_ptr<IModel> _model) : IPresent(_view, _model) {};
    ~SearchPresent() override {};
    void ChangeView() override {};
    void HandleButton(ButtonEvent &) override {};
    void SetFilter();
    void Update() override {};

private:
    Filter filters;
};


#endif //SOUNDMATE_PRESENTORS_H
