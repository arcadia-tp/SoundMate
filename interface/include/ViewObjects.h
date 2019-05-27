#ifndef SOUNDMATE_VIEWOBJECTS_H
#define SOUNDMATE_VIEWOBJECTS_H

#include <string>
#include <memory>
#include <iostream>
//#include "ViewEvents.h"

class IInteractNotify {
public:
    IInteractNotify() = default;
    virtual ~IInteractNotify() = 0;
};

template <typename Type>
class InteractNotify : IInteractNotify {
public:
    explicit InteractNotify(Type info) : info(info) {};
    Type getEvent() {
        return info;
    }
private:
    Type info;
};


class ViewObject {
public:
    // NOTE: Черновой вариант
    ViewObject() = default;
//    ViewObject(std::string& _id) : id(_id) {};
    virtual ~ViewObject() {};
    virtual void show() const = 0;
    // TODO: О неудачной отрисовке можно сообщать в виде исключения
protected:
//    std::string id;
};

class TextObject : public ViewObject {
public:
    TextObject() : ViewObject() {};

    explicit TextObject(std::string _data) : data(_data) {};
    ~TextObject() override {};
    void SetData(std::string _data) {
        data = _data;
    }
    void show() const override;
private:
    std::string data;
};


struct ImageSource {
    // TODO: add logic
};

class Image : public ViewObject {
public:
    Image() : ViewObject() {};
    explicit Image(ImageSource img) : source(img) {};
    ~Image() override {};
    void SetImage(ImageSource img) {
        source = img;
    }
    void show() const override;
private:
    ImageSource source;
};

class Field : public ViewObject {
public:
    enum States {
        EMPTY = 0,
        FILLED
    };
    Field() : ViewObject(), title("undeclared"), state(EMPTY) {};
    explicit Field(std::string& _title) : ViewObject(), title(_title), state(EMPTY) {};
    ~Field() override {};

    // TODO: общий stream?
    bool input(std::istream& in) {
        std::string tmp;
        while (!in.eof()) {
            in >> tmp;
            data += tmp;
        }
        // TODO: Обработка ошибок потока
        checkFilled();
        return true;
    }

    void show() const override;



    inline const std::string& getData() const {
        return data;
    };
    inline const std::string getTitle() const {
        return title;
    }

    inline bool check(IInteractNotify& info) {

    }
    inline void clear() {
        data.clear();
        checkFilled();
    }
    States state;
private:
    inline bool checkFilled() {
        if (!data.empty()) {
            state = FILLED;
        } else {
            state = EMPTY;
        }
    };
    std::string title;
    std::string data;
};


//template <typename Info>
class Button : public ViewObject {
public:


    enum Type {
        DEFAULT = -1,
        QUIT = 0,
        BACK,
        SWITCH,
        COMMAND
    };

    Button() : ViewObject(), type(DEFAULT), status(NOT_EXEC), referer("None"), title("undeclared") {};
    Button(Type _type, std::string& _referer, std::string& _title)
    try : ViewObject(), type(_type), status(NOT_EXEC), referer(_referer), title(_title) {
        if (type != SWITCH && type != COMMAND) {
            throw std::invalid_argument("type and referer doesn't match");
        }
    } catch (std::invalid_argument& ia) {
        std::cerr << "Button constructor: " << ia.what() << std::endl;
    }
    ~Button() override {};
    enum Status {
        EXEC = 0,
        NOT_EXEC
    };
    void show() const override;
    inline virtual bool check(IInteractNotify& info) {

    }
    inline const std::string getReferer() const {
        return referer;
    }
    Type type;
    Status status;
private:
    std::string referer;
    std::string title;
};

#endif //SOUNDMATE_VIEWOBJECTS_H
