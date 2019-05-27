#ifndef SOUNDMATE_VIEWS_H
#define SOUNDMATE_VIEWS_H

#include "ViewObjects.h"
#include "PresentEvents.h"
#include "PresentListeners.h"
#include "Utils.h"
#include <vector>
#include <memory>


class IView {
public:
    IView() = default;
    virtual ~IView() = 0;
    virtual bool Show() = 0;
    virtual void Close() = 0;
    virtual void ShowButtons() = 0;
    bool SetButton(Button&);
//    std::vector<Event> GetEvent();

protected:
    // NOTE: По факту, тут может быть просто перечисление всех объектов - поля, кнопки, объекты
    // Чтобы иметь возможность проитерироваться
    std::vector<std::shared_ptr<ViewObject>> objectList;
//    std::vector<std::shared_ptr<Button>> buttons;
//    ButtonEvent getButtonEvent();
//    ListenerButton buttonsListener;
};

//IView::~IView() {};

class IViewWithFields : public IView {
public:
    IViewWithFields() : IView() {};
    ~IViewWithFields() override {};
    bool SetField(Field&);
    virtual void ShowFields() = 0;

protected:
//    std::vector<std::shared_ptr<Field>> fields;
//    FieldEvent getFieldEvent();
//    ListenerField fieldsListener;
};

class MainScreenView : public IViewWithFields {
public:
    MainScreenView() : IViewWithFields() {};
    ~MainScreenView() override {};
    void ShowUsers(std::vector<std::shared_ptr<User>>);
    void ShowFields() override {};
    void ShowButtons() override {};
    void ShowBio();
    void ShowAutorization();
    bool Show() override {};
    void Close() override {};
private:
//    Image Background;
//    Image Logo;
//    TextObject Greeting;
//    Button SignIn;
//    Button SignUp;
//    Button Join;
//    Button Quit;
//    Button GetRandomUsers;
//    Field Login;
//    Field Password;
};

class RegisterScreenView : public IViewWithFields {
public:
    RegisterScreenView() : IViewWithFields() {};
    ~RegisterScreenView() override {};
    void ShowFields() override {};
    void ShowButtons() override {};
    void ShowError();
    bool Show() override {};
    void Close() override {};
private:
    Image Background;
    TextObject Status;
    std::vector<Field> dataFields;
    Button SignUp;
};

class UserScreenView : public IViewWithFields {
    UserScreenView() : IViewWithFields() {};
    ~UserScreenView() override {};
    void ShowFields() override {};
    void ShowButtons() override {};
    void ShowError();
    void ShowFriendList(std::vector<std::shared_ptr<User>>);
    bool Show() override {};
    void Close() override {};
};

class MessengerScreenView : public IViewWithFields {
public:
    MessengerScreenView() : IViewWithFields() {};
    ~MessengerScreenView() override {};
    void ShowFields() override {};
    void ShowButtons() override {};
    void ShowError();
    bool ShowChatList(std::vector<std::shared_ptr<Chat>>);
    bool ShowChat(Chat &);
    bool Show() override {};
    void Close() override {};
};

class SearchScreenView : public IView {
public:
    SearchScreenView() : IView() {};
    ~SearchScreenView() override {};
    void ShowButtons() override {};
    void ShowUsers(std::vector<std::shared_ptr<User>>);
    void ShowBio();
    void ShowFilters(Filter &);
    bool Show() override {};
    void Close() override {};
};

#endif //SOUNDMATE_VIEWS_H
