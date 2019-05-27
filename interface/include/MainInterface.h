#ifndef SOUNDMATE_MAININTERFACE_H
#define SOUNDMATE_MAININTERFACE_H

#include <vector>
#include <memory>
#include "Presentors.h"

class Screen {
public:
    // А-ля синглтон
    static Screen& getInstance(std::shared_ptr<IPresent> startScreen = std::dynamic_pointer_cast<IPresent>(
            std::make_shared<MainScreenPresent>(std::make_shared<MainScreenView>(), std::make_shared<MainScreenModel>()))) {
        static Screen _instance(startScreen);
        return _instance;
    }

    void runPresentor();
    void switchPresentor();
private:
    explicit Screen(std::shared_ptr<IPresent>& startScreen) : currentPresent(startScreen), currentSession(0) {};
    ~Screen() {};
    std::vector<std::shared_ptr<IPresent>> presentors;
    std::shared_ptr<IPresent> currentPresent;
    int currentSession;
};


#endif //SOUNDMATE_MAININTERFACE_H
