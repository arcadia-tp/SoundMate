#include "DataBasePerson.h"

#include <boost/lexical_cast.hpp>


// Class PrivateData **********************

PrivateData::PrivateData(){}
PrivateData::~PrivateData(){}

void PrivateData::setId(int id_value){
    id = id_value;
}

void PrivateData::setLogin(std::string login_value){
    login = login_value;
}

void PrivateData::setPassword(std::string password_value){
    password = password_value;
}

int PrivateData::getID(){
    return id;
}

std::string PrivateData::getLogin(){
    return login;
}

std::string PrivateData::getPassword(){
    return password;
}

// Class PersonalData *********************

PersonalData::PersonalData(){}
PersonalData::~PersonalData(){}

void PersonalData::setNameSurname(std::string name_value, std::string surname_value){
    name = name_value;
    surname = surname_value;
}

void PersonalData::setBirthDate(std::string date){
    birth_date = date;
}

void PersonalData::setPersonalInfo(std::string info){
    personal_information = info;
}

std::string PersonalData::getName(){
    return name;
}

std::string PersonalData::getSurname() {
    return surname;
}

std::string PersonalData::getBirthDate(){
    return birth_date;
}

std::string PersonalData::getPersonalInfo(){
    return personal_information;
}

// Class CommunicationData ****************

CommunicationData::CommunicationData(){}
CommunicationData::~CommunicationData(){}

void CommunicationData::setCommunicationData(std::string app, std::string path){
    communication_list[app] = path;
}

std::string CommunicationData::getCommunicationData(std::string app){
    std::map <std::string, std::string>:: iterator it;
    std::string path;

    it = communication_list.find(app);
    if (it != communication_list.end())
        path = it->second;
    else return NULL;
    return path;
}

// Class PersonalMusic ********************

PersonalMusic::PersonalMusic(){}
PersonalMusic::~PersonalMusic(){}

void PersonalMusic::setMusicalInstruments(std::string instrument){
    musical_instruments.insert(instrument);
}

void PersonalMusic::setMusicalGenres(std::string genre){
    musical_genres.insert(genre);
}

std::string PersonalMusic::forFileInstr() {
    std::string str;
    
    if (musical_instruments.size() == 0) return " i_-";

    std::set<std::string>::iterator it;
    for (it = musical_instruments.begin(); it != musical_instruments.end(); it++) {
        str += " i_" + *it;
    }
    return str;
}

std::string PersonalMusic::forFileGenre() {
    std::string str;

    if (musical_genres.size() == 0) return " g_-";

    std::set<std::string>::iterator it;
    for (it = musical_genres.begin(); it != musical_genres.end(); it++) {
        str += " g_" + *it;
    }
    return str;
}

std::set<std::string> PersonalMusic::getMusicalInstruments(){
    return musical_instruments;
}

std::set<std::string> PersonalMusic::getMusicalGenres(){
    return musical_genres;
}

// Class DropdownList *********************

DropdownList::DropdownList(){
    musical_instrument = { "guitar","piano","violin","drums","flute" };
    musical_genre = { "jazz","classic", "techno" };
}
DropdownList::~DropdownList(){}

int DropdownList::getCountInstr() {
    return musical_instrument.size();
}

int DropdownList::getCountGenre() {
    return musical_genre.size();
}

std::string DropdownList::getMusicalInstrument(int id){
    return musical_instrument[id];
}

std::string DropdownList::getMusicalGenre(int id){
    return musical_genre[id];
}

// Class PersonalMedia ********************

PersonalMedia::PersonalMedia(){}
PersonalMedia::~PersonalMedia(){}

void PersonalMedia::setAvatarPhoto(std::string avatar){
    avatar_photo = avatar;
}
std::string PersonalMedia::getAvatarPhoto(){
    return avatar_photo;
}


// Class Friends **************************

Friends::Friends(){}
Friends::~Friends(){}

void Friends::setFriend(std::string id){
    int id_ = boost::lexical_cast<int> (id);
    friends_id.push_back(id_);
}

std::string Friends::getFriends() {
    std::string str = "";

    if (friends_id.size() == 0)
        return "-";
    else {
        for (int i = 0; i < friends_id.size() - 1; i++)
            str += boost::lexical_cast<std::string>(friends_id[i]) + ' ';
        str += boost::lexical_cast<std::string>(friends_id[friends_id.size() - 1]);
    }
    return str;
}

// Class UserData *************************

UserData::UserData(){}
UserData::~UserData(){}