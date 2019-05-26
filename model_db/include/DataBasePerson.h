#ifndef DATABASEPERSON_H_
#define DATABASEPERSON_H_

#include <vector>
#include <cstring>
#include <map>
#include <set>

#include "DataBaseMessanger.h"


class PrivateData {
public:
    PrivateData();
    ~PrivateData();

    void setId(int id_value);
    void setLogin(std::string login_value);
    void setPassword(std::string password_value);
    int getID();
    std::string getLogin();
    std::string getPassword();
private:
    int id_;
    std::string login_;
    std::string password_;
};

class PersonalData {
public:
    PersonalData();
    ~PersonalData();

    void setNameSurname(std::string name_value, std::string surname_value);
    void setBirthDate(std::string date);
    void setPersonalInfo(std::string info);
    std::string getName();
    std::string getSurname();
    std::string getBirthDate();
    std::string getPersonalInfo();
private:
    std::string name_;
    std::string surname_;
    std::string birth_date_;
    std::string personal_information_;
};

class CommunicationData {
public:
    CommunicationData();
    ~CommunicationData();

    void setCommunicationData(std::string app, std::string path);
    std::string getCommunicationData(std::string app);
private:
    std::map<std::string, std::string> communication_list_;
};

class DropdownList {
public:
    DropdownList();
    ~DropdownList();

    std::string getMusicalInstrument(int id);
    std::string getMusicalGenre(int id);
    int getCountInstr();
    int getCountGenre();
private:
    std::vector<std::string> musical_instrument_;
    std::vector<std::string> musical_genre_;
};

class PersonalMusic {
public:
    PersonalMusic();
    ~PersonalMusic();

    void setMusicalInstruments(std::string instrument);
    void setMusicalGenres(std::string genre);
    std::string forFileInstr();
    std::string forFileGenre();
    std::set<std::string> getMusicalInstruments();
    std::set<std::string> getMusicalGenres();
private:
    std::set<std::string> musical_instruments_;
    std::set<std::string> musical_genres_;
};

class PersonalMedia {
public:
    PersonalMedia();
    ~PersonalMedia();

    void setAvatarPhoto(std::string avatar);
    std::string getAvatarPhoto();
private:
    std::string avatar_photo_;
};

class Friends {
public:
    Friends();
    ~Friends();

    void setFriend(std::string id);
    std::string getFriends();
private:
    std::vector<int> friends_id_;
};

class UserData :public PrivateData {
public:
    PersonalData personal_data_;
    PersonalMusic personal_music_;
    CommunicationData contact_data_;
    PersonalMedia personal_media_;
    Friends friends_;
    //std::vector<Chat> chat_list;

    UserData();
    ~UserData();
};

#endif // DATABASEPERSON_H_
