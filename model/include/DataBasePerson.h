#ifndef DATABASEPERSON_H_
#define DATABASEPERSON_H_

#include <vector>
#include <cstring>
#include <map>
#include <set>
#include "DataBaseMessanger.h"


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
    void setBirthDate(std::string date);
    void setPersonalInfo(std::string info);
    std::string getName();
    std::string getSurname();
    std::string getBirthDate();
    std::string getPersonalInfo();
};

class CommunicationData {
private:
    std::map<std::string, std::string> communication_list;
public:
    CommunicationData();
    ~CommunicationData();

    void setCommunicationData(std::string app, std::string path);
    std::string getCommunicationData(std::string app);
};

class DropdownList {
private:
    std::vector<std::string> musical_instrument;
    std::vector<std::string> musical_genre;
public:
    DropdownList();
    ~DropdownList();

    std::string getMusicalInstrument(int id);
    std::string getMusicalGenre(int id);
    int getCountInstr();
    int getCountGenre();
};

class PersonalMusic {
private:
    std::set<std::string> musical_instruments;
    std::set<std::string> musical_genres;
public:
    PersonalMusic();
    ~PersonalMusic();

    void setMusicalInstruments(std::string instrument);
    void setMusicalGenres(std::string genre);
    std::string forFileInstr();
    std::string forFileGenre();
    std::set<std::string> getMusicalInstruments();
    std::set<std::string> getMusicalGenres();
};

class PersonalMedia {
private:
    std::string avatar_photo;
public:
    PersonalMedia();
    ~PersonalMedia();

    void setAvatarPhoto(std::string avatar);
    std::string getAvatarPhoto();
};

class Friends {
private:
    std::vector<int> friends_id;
public:
    Friends();
    ~Friends();

    void setFriend(std::string id);
    std::string getFriends();
};

class UserData :public PrivateData {
public:
    PersonalData personal_data;
    PersonalMusic personal_music;
    CommunicationData contact_data;
    PersonalMedia personal_media;
    Friends friends;
    //std::vector<Chat> chat_list;

    UserData();
    ~UserData();
};

#endif // DATABASEPERSON_H_
