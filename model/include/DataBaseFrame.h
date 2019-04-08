#ifndef DATABASEFRAME_H_
#define DATABASEFRAME_H_

#include <vector>
#include <cstring>
#include <map>

class PrivateData {
private:
    int id;
    std::string login;
    std::string password;
public:
    PrivateData();
    ~PrivateData();

    void setId(int id_value);
    void setLogin(std::string login_value);
    void setPassword(std::string password_value);
    int getID();
    std::string getLogin();
    std::string getPassword();
};

class PersonalData {
private:
    std::string name;
    std::string surname;
    std::string birth_date;
    std::string personal_information;
public:
    PersonalData();
    ~PersonalData();

    void setNameSurname(std::string name_value, std::string surname_value);
    void setBirthDate(std::string);
    void setPersonalInfo(std::string info);
    std::string getNameSurname();
    std::string getBirthDate();
    std::string getPersonalInfo();
};

class CommunicationData {
private:
    std::map<std::string, std::string> communication_list;
public:
    CommunicationData();
    ~CommunicationData();

    void setCommunicationData(std::string);
    std::string getCommunicationData();
};

class PersonalMusic {
private:
    std::vector<std::string> musical_instruments;
    std::vector<std::string> musical_genres;
public:
    PersonalMusic();
    ~PersonalMusic();

    void setMusicalInstruments(DropdownList instrumens_list);
    void setMusicalGenres(DropdownList generes_list);
    std::vector<std::string> getMusicalInstruments();
    std::vector<std::string> getMusicalGenres();
};

class DropdownList {
private:
    std::vector<std::string> musical_instrument;
    std::vector<std::string> musical_genre;
public:
    DropdownList();
    ~DropdownList();

    std::string getMusicalInstrument();
    std::string getMusicalGenre();
};

class PersonalMedia {
private:
    std::string avatar_photo;
    std::vector<std::string> video;
public:
    PersonalMedia();
    ~PersonalMedia();

    void setAvatarPhoto(std::string);
    void setVideo(std::string);
    std::string getAvatarPhoto();
    std::string getVideo(int video_index);
};

class Friends {
private:
    std::vector<int> friends_id;
public:
    Friends();
    ~Friends();

    void setFriend(int id);
};

class Chat {
private:
    int chat_id;
    std::string name;
    std::vector<int> user_list;
    std::vector<Message> chat_massages;
public:
    Chat();
    ~Chat();

    void setName(std::string);
    void addUser(int id);
    void addMessage(int id, std::string content, std::string date);
    int getId();
    std::string getName();
    std::vector<int> getUserList();
    TextMessage getTextMessage(int id_m);
    PictureMessage getPictureMessage(int id_m);
};

class Message {
private:
    int id;
    std::string date_creating;
public:
    virtual int getId() = 0;
    virtual std::string getContent() = 0;
};

class TextMessage :public Message {
private:
    std::string text_content;
public:
    TextMessage();
    ~TextMessage();

    int getId() override;
    std::string getContent() override;
};

class PictureMessage :public Message {
private:
    std::string picture_content;
public:
    PictureMessage();
    ~PictureMessage();

    int getId() override;
    std::string getContent() override;
};

class UserData:public PrivateData {
public:
    PersonalData personal_data;
    PersonalMusic personal_music;
    CommunicationData contect_data;
    std::vector<Chat> chat_list;
    PersonalMedia personal_media;
    Friends friends;

    UserData();
    ~UserData();
};

#endif // DATABASEFRAME_H_
