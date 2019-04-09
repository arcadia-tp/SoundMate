#ifndef SOUNDMATE_PRESENTORS_H
#define SOUNDMATE_PRESENTORS_H

#include <vector>
#include "Views.h"
#include "Models.h"


class IPresent {
public:
    IPresent(IView* _view, IModel* _model) : model(_model), currentView(_view) {
        views.push_back(currentView);
    }
    virtual ~IPresent() = 0;
    virtual void changeView() = 0;
    virtual void update() = 0;
private:
    IModel* model;
    std::vector<IView *> views;
    IView* currentView;
};

IPresent::~IPresent() {
    delete model;
    for (auto view : views) {
        delete view;
    }
}

class IPresentButtonable : public IPresent {
public:
    IPresentButtonable(IView* _view, IModel* _model) : IPresent(_view, _model) {};
    ~IPresentButtonable() override {};
    virtual bool handleButton(Event &) = 0;
};

class MainScreenPresent : public IPresentButtonable {
public:
    MainScreenPresent(IView* _view, IModel* _model) : IPresentButtonable(_view, _model) {};
    ~MainScreenPresent() override {};
    void changeView() override {};
    bool handleButton(Event &) override {};
    void handlerFields();
    void update() override {};
};

class RegisterScreenPresent : public IPresentButtonable {
public:
    RegisterScreenPresent(IView* _view, IModel* _model) : IPresentButtonable(_view, _model) {};
    ~RegisterScreenPresent() override {};
    void changeView() override {};
    bool handleButton(Event &) override {};
    void handleFields();
    void update() override {};
};

class UserScreenPresent : public IPresentButtonable {
public:
    UserScreenPresent(IView* _view, IModel* _model) : IPresentButtonable(_view, _model) {};
    ~UserScreenPresent() override {};
    void changeView() override {};
    bool handleButton(Event &) override {};
    bool handleFields();
    void update() override {};

private:
    std::vector<User *> friends;
};

class MessengerScreenPresent : public IPresentButtonable {
public:
    MessengerScreenPresent(IView* _view, IModel* _model) : IPresentButtonable(_view, _model) {};
    ~MessengerScreenPresent() override {};
    void changeView() override {};
    bool handleButton(Event &) override {};
    bool handleFields();
    void getChats();
    void update() override {};

private:
    std::vector<Chat *> chats;
    std::vector<Message *> messages;
};

class SearchPresent : public IPresentButtonable {
public:
    SearchPresent(IView* _view, IModel* _model) : IPresentButtonable(_view, _model) {};
    ~SearchPresent() override {};
    void changeView() override {};
    bool handleButton(Event &) override {};
    void setFilter();
    void update() override {};

private:
    Filter filters;
};


#endif //SOUNDMATE_PRESENTORS_H
