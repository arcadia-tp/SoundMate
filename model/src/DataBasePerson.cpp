#include "DataBasePerson.h"

#include <boost/lexical_cast.hpp>


// Класс PrivateData **********************

PrivateData::PrivateData(){}
PrivateData::~PrivateData(){}

void PrivateData::setId(int id_value){
    id_ = id_value;
}

void PrivateData::setLogin(std::string login_value){
    login_ = login_value;
}

void PrivateData::setPassword(std::string password_value){
    password_ = password_value;
}

int PrivateData::getID(){
    return id_;
}

std::string PrivateData::getLogin(){
    return login_;
}

std::string PrivateData::getPassword(){
    return password_;
}

// Класс PersonalData *********************

PersonalData::PersonalData(){}
PersonalData::~PersonalData(){}

void PersonalData::setNameSurname(std::string name_value, std::string surname_value){
    name_ = name_value;
    surname_ = surname_value;
}

void PersonalData::setBirthDate(std::string date){
    birth_date_ = date;
}

void PersonalData::setPersonalInfo(std::string info){
    personal_information_ = info;
}

std::string PersonalData::getName(){
    return name_;
}

std::string PersonalData::getSurname() {
    return surname_;
}

std::string PersonalData::getBirthDate(){
    return birth_date_;
}

std::string PersonalData::getPersonalInfo(){
    return personal_information_;
}

// Класс CommunicationData ****************

CommunicationData::CommunicationData(){}
CommunicationData::~CommunicationData(){}

void CommunicationData::setCommunicationData(std::string app, std::string path){
    communication_list_[app] = path;
}

std::string CommunicationData::getCommunicationData(std::string app){
    std::map <std::string, std::string>:: iterator it;
    std::string path;

    it = communication_list_.find(app);
    if (it != communication_list_.end())
        path = it->second;
    else return NULL;
    return path;
}

// Класс PersonalMusic ********************

PersonalMusic::PersonalMusic(){}
PersonalMusic::~PersonalMusic(){}

void PersonalMusic::setMusicalInstruments(std::string instrument){
    musical_instruments_.insert(instrument);
}

void PersonalMusic::setMusicalGenres(std::string genre){
    musical_genres_.insert(genre);
}

std::string PersonalMusic::forFileInstr() {
    std::string str;
    
    if (musical_instruments_.size() == 0) return " -";

    std::set<std::string>::iterator it;
    for (it = musical_instruments_.begin(); it != musical_instruments_.end(); it++) {
        str += " " + *it;
    }
    return str;

    //if(musical_instruments.size)
}

std::string PersonalMusic::forFileGenre() {
    std::string str;

    if (musical_genres_.size() == 0) return " -";

    std::set<std::string>::iterator it;
    for (it = musical_genres_.begin(); it != musical_genres_.end(); it++) {
        str += " " + *it;
    }
    return str;
}

std::set<std::string> PersonalMusic::getMusicalInstruments(){
    return musical_instruments_;
}

std::set<std::string> PersonalMusic::getMusicalGenres(){
    return musical_genres_;
}

// Класс DropdownList *********************

DropdownList::DropdownList(){
    musical_instrument_ = { "guitar","piano","violin","drums","flute" };
    musical_genre_ = { "jazz","classic", "techno" };
}
DropdownList::~DropdownList(){}

int DropdownList::getCountInstr() {
    return musical_instrument_.size();
}

int DropdownList::getCountGenre() {
    return musical_genre_.size();
}

std::string DropdownList::getMusicalInstrument(int id){
    return musical_instrument_[id];
}

std::string DropdownList::getMusicalGenre(int id){
    return musical_genre_[id];
}

// Класс PersonalMedia ********************

PersonalMedia::PersonalMedia(){}
PersonalMedia::~PersonalMedia(){}

void PersonalMedia::setAvatarPhoto(std::string avatar){
    avatar_photo_ = avatar;
}
std::string PersonalMedia::getAvatarPhoto(){
    return avatar_photo_;
}


// Класс Friends **************************

Friends::Friends(){}
Friends::~Friends(){}

void Friends::setFriend(std::string id){
    int id_ = boost::lexical_cast<int> (id);
    friends_id_.push_back(id_);
}

std::string Friends::getFriends() {
    std::string str = "";

    if (friends_id_.size() == 0)
        return "-";
    else {
        for (int i = 0; i < friends_id_.size() - 1; i++)
            str += boost::lexical_cast<std::string>(friends_id_[i]) + ' ';
        str += boost::lexical_cast<std::string>(friends_id_[friends_id_.size() - 1]);
    }
    return str;
}

// Класс UserData *************************

UserData::UserData(){}
UserData::~UserData(){}