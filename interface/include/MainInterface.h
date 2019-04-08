#ifndef SOUNDMATE_MAININTERFACE_H
#define SOUNDMATE_MAININTERFACE_H

#include <vector>
#include "Presentors.h"

class Screen {
public:
    // А-ля синглтон
    static Screen& getInstance(IPresent* startScreen =
            new MainScreenPresent(new MainScreenView(), new MainScreenModel())) {
        static Screen _instance(startScreen);
        return _instance;
    }

    void runPresentor();
    void switchPresentor();
private:
    explicit Screen(IPresent* startScreen) : currentPresent(startScreen), currentSession(0) {};
    ~Screen() {};
    std::vector<IPresent *> presentors;
    IPresent* currentPresent;
    int currentSession;
};


#endif //SOUNDMATE_MAININTERFACE_H
