#ifndef SOUNDMATE_VIEWS_H
#define SOUNDMATE_VIEWS_H

#include <vector>
#include "Utils.h"


class IView {
public:
    IView() = default;
    virtual ~IView() = 0;
    virtual bool show() = 0;
    virtual void close() = 0;
    Event& getEvent();

private:
    std::vector<ViewObject *> objectList;
};

IView::~IView() {}

class IViewButtonable : public IView {
public:
    IViewButtonable() : IView() {};
    ~IViewButtonable() override {};
    virtual void showButtons() = 0;
    bool setButton(ButtonEvent&);

private:
    std::vector<Button *> buttons;
};


class MainScreenView : public IViewButtonable {
public:
    MainScreenView() : IViewButtonable() {};
    ~MainScreenView() override {};
    void showUsers(std::vector<User *>);
    void showFields();
    void showButtons() override {};
    void showBio();
    void showAutorization();
    bool show() override {};
    void close() override {};
};

class RegisterScreenView : public IViewButtonable {
public:
    RegisterScreenView() : IViewButtonable() {};
    ~RegisterScreenView() override {};
    void showFields();
    void showButtons() override {};
    void showError();
    bool show() override {};
    void close() override {};

private:
    std::vector<Field *> fieldList;
};

class UserScreenView : public IViewButtonable {
    UserScreenView() : IViewButtonable() {};
    ~UserScreenView() override {};
    void showFields();
    void showButtons() override {};
    void showError();
    void showFriendList(std::vector<User *>);
    bool show() override {};
    void close() override {};

private:
    std::vector<Field *> fieldList;
};

class MessengerScreenView : public IViewButtonable {
public:
    MessengerScreenView() : IViewButtonable() {};
    ~MessengerScreenView() override {};
    void showFields();
    void showButtons() override {};
    void showError();
    bool shoeChatList(std::vector<Chat *>);
    bool showChat(Chat &);
    bool show() override {};
    void close() override {};

private:
    std::vector<Field *> fieldList;
};

class SearchScreenView : public IViewButtonable {
public:
    SearchScreenView() : IViewButtonable() {};
    ~SearchScreenView() override {};
    void showButtons() override {};
    void showUsers(std::vector<User *>);
    void showBio();
    void showFilters(Filter &);
    bool show() override {};
    void close() override {};
};

#endif //SOUNDMATE_VIEWS_H
