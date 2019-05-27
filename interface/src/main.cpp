#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <memory>

#include "MainInterface.h"
#include "Presentors.h"


class Root {
public:
    Root();
    ~Root() = default;
    bool Update();
private:
    std::stack<std::shared_ptr<IPresent>> applicationStack;
};

Root::Root() {
    std::shared_ptr<IPresent> mainPresent = std::make_shared<MainScreenPresent>(std::make_shared<MainScreenView>(), std::make_shared<MainScreenModel>());
//    std::shared_ptr<IPresent> inStack = std::dynamic_pointer_cast<IPresent>(mainPresent);
//    IPresent *smth = new MainScreenPresent(std::make_shared<MainScreenView>(), std::make_shared<MainScreenModel>());
//    IPresent *smth2 = smth;
//    applicationStack.emplace(std::dynamic_pointer_cast<IPresent<IView>>(mainPresent));
    applicationStack.emplace(mainPresent);
}

bool Root::Update() {
    //TODO: Обработка эфентов, опрос представлений, обработка презенторов
    std::shared_ptr<IPresent> mainScr = std::dynamic_pointer_cast<IPresent>(applicationStack.top());
    mainScr->Update();
    return false;
}

int main(int argc, const char **argv) {
    Root root;
    while (root.Update());
//    Event event;
//    event.type = Event::ButtonExec;
//    event.button = ButtonEvent();
//    std::shared_ptr<IPresent> mainPresent = std::make_shared<MainScreenPresent>(std::make_shared<MainScreenView>(), std::make_shared<MainScreenModel>());
//    Screen &MainScreen = Screen::getInstance(mainPresent);
    std::cout << "Hi :3" << std::endl;
    return 0;
}

