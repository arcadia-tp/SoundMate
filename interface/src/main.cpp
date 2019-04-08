#include <iostream>
#include <string>
#include <vector>

#include "MainInterface.h"
#include "Presentors.h"


int main(int argc, const char **argv) {

    IPresent* mainPresent = new MainScreenPresent(new MainScreenView(), new MainScreenModel());
    Screen &MainScreen = Screen::getInstance(mainPresent);
    std::cout << "Hi :3" << std::endl;
    delete mainPresent;
    return 0;
}

