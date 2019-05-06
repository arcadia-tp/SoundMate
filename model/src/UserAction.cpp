#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <regex>

#include "UserActionFrame.h"

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#define MEDIA 3


std::string DeleteTheUnderScore(std::string str);
void CreateData(UserData *user, std::set<std::string> logins);
void CreateAnotherData(UserData *user);
void WriteFileOut(std::ofstream&file, UserData* user);
std::string GetLogin(std::string str);
void TakeDataFromFile(std::ifstream&file, UserData* user);
bool CheckI_(std::string str);
bool CheckG_(std::string str);
std::vector<std::string> ReadPersonFile();
void WriteToFile(std::string filename, UserData *user);


UserData* UserAction::getUser(int id_user){
    std::string str;
    std::string filename = "DB\\",f;
    int users_num = 0;

    std::ifstream F_PERSON;
    f = filename + "person.txt";
    F_PERSON.open(f);
    if (!F_PERSON.is_open()) {
        std::cout << "\nERR READING FILE" << std::endl;
        return NULL;
    }

    std::getline(F_PERSON, str);
    users_num = boost::lexical_cast<int> (str);

    if (users_num == 0) {
        std::cout << "\nNO DATA" << std::endl;
        return NULL;
    }
    bool include = false;
    while (!F_PERSON.eof() && include==false) {
        std::getline(F_PERSON, str);
        if (boost::starts_with(str, boost::lexical_cast<std::string> (id_user))) {
            include = true;
        }
    }
    if (include == false) {
        std::cout << "\nNO id" << std::endl;
        return NULL;
    }
    F_PERSON.close();

    std::ifstream F_TAKEDATA;
    f = filename + boost::lexical_cast<std::string> (id_user) + ".txt";
    F_TAKEDATA.open(f);
    if (!F_TAKEDATA.is_open()) {
        std::cout << "\nERR READING FILE" << std::endl;
        return NULL;
    }
    UserData *user = new UserData;
    TakeDataFromFile(F_TAKEDATA, user);
    F_TAKEDATA.close();

    return user;
}

void UserAction::printUser(UserData *user){
    if (user == NULL) {
        std::cout << "EMPTY USER" << std::endl;
        return;
    }

    std::cout << "id: " << user->getID() << std::endl;
    std::cout << "login: " << user->getLogin() << std::endl;
    std::cout << "password: " << user->getPassword() << std::endl;
    std::cout << "name: " << user->personal_data.getName() << std::endl;
    std::cout << "surname: " << user->personal_data.getSurname() << std::endl;
    std::cout << "birthdate: " << user->personal_data.getBirthDate() << std::endl;
    std::cout << "info: " << user->personal_data.getPersonalInfo() << std::endl;
    std::cout << "avatar: " << user->personal_media.getAvatarPhoto() << std::endl;
    std::cout << "vk: " << user->contact_data.getCommunicationData("vk") << std::endl;
    std::cout << "mail: " << user->contact_data.getCommunicationData("mail") << std::endl;
    std::cout << "number: " << user->contact_data.getCommunicationData("number") << std::endl;
    std::cout << "instruments:" << user->personal_music.forFileInstr() << std::endl;
    std::cout<<"genres: "<< user->personal_music.forFileGenre() << std::endl;
    std::cout << "friends: " << user->friends.getFriends() << std::endl;
}

UserData* UserAction::createUser(){
    std::string str;
    std::string filename = "DB\\", f;
    int users_num = 0;

    std::vector<std::string> data;
    std::set<std::string> logins;
    UserData* user = new UserData;

    std::ifstream F_PERSON;
    f = filename + "person.txt";
    F_PERSON.open(f);
    if (!F_PERSON.is_open()) {
        std::cout << "\nERR READING FILE" << std::endl;
        return NULL;
    }

    std::getline(F_PERSON, str);
    users_num = boost::lexical_cast<int> (str);
    if (users_num != 0) {
        while (!F_PERSON.eof()) {
            std::getline(F_PERSON, str);
            data.push_back(str);
            logins.insert(GetLogin(str));
        }
    }
    F_PERSON.close();

    users_num+=1;
    user->setId(users_num);
    CreateData(user, logins);
    CreateAnotherData(user);

    std::ofstream OUT_PERSON;
    f = filename + "person.txt";
    OUT_PERSON.open(f);
    if (!OUT_PERSON.is_open()) {
        std::cout << "\nERR READING FILE" << std::endl;
        return NULL;
    }
    else {
        OUT_PERSON << users_num << std::endl;
        std::vector<std::string>::iterator it;
        for (it = data.begin(); it != data.end(); it++) {
            OUT_PERSON << *it << std::endl;
        }

        OUT_PERSON << users_num;
        OUT_PERSON << " " << user->getLogin() << " " << user->getPassword();
        OUT_PERSON << user->personal_music.forFileInstr() << user->personal_music.forFileGenre();
    }
    OUT_PERSON.close();

    std::ofstream F_NEWFILE;
    f = filename + boost::lexical_cast<std::string> (users_num) + ".txt";
    F_NEWFILE.open(f);
    if (!F_NEWFILE.is_open()) {
        std::cout << "\nERR READING FILE" << std::endl;
        return NULL;
    }
    else {
        WriteFileOut(F_NEWFILE, user);
    }
    F_NEWFILE.close();

    return user;
}

void UserAction::changeInfo(UserData *user) {
    if (user == NULL) {
        std::cout << "ERR USER" << std::endl;
        return;
    }

    bool go = true;
    bool change_count = false;
    int action;

    std::vector<std::string> data = ReadPersonFile();

    while (go) {
        std::cout << "\n0: Exit\n1: Change name\n2: Change surname\n3: Chage info about you\n4: Change avatar\n5: Change contact data" << std::endl;
        std::cin >> action;
        switch (action) {
        case 0:
            go = false;
            break;

        case 1:
            changeName(user);
            change_count = true;
            break;

        case 2:
            changeSurname(user);
            change_count = true;
            break;

        case 3:
            changeInformation(user);
            change_count = true;
            break;

        case 4:
            changeAvatar(user);
            change_count = true;
            break;

        case 5:
            changeContactData(user);
            change_count = true;
            break;

        default:
            std::cout << "Error action. Try again.\n";
            break;
        }
    }
    if (change_count == true) {
        std::string filename = "DB\\" + boost::lexical_cast<std::string>(user->getID()) + ".txt";
        WriteToFile(filename, user);
    }
}

void UserAction::changeName(UserData *user) {
    std::cout << "Write new name: ";
    std::string str;
    std::cin >> str;
    user->personal_data.setNameSurname(str, user->personal_data.getSurname());
}

void UserAction::changeSurname(UserData *user) {
    std::cout << "Write new Surname: ";
    std::string str;
    std::cin >> str;
    user->personal_data.setNameSurname(user->personal_data.getName(),str);
}

void UserAction::changeInformation(UserData *user) {
    std::cout << "Write new info about you: ";
    std::string str;
    std::cin.get();
    std::getline(std::cin, str);
    user->personal_data.setPersonalInfo(str);
}

void UserAction::changeAvatar(UserData *user) {
    std::cout << "Write new avatar path: ";
    std::string str;
    std::cin >> str;
    user->personal_media.setAvatarPhoto(str);
}

void UserAction::changeContactData(UserData *user) {
    std::cout << "\nChoose:\n";
    int action;
    bool go = true;
    std::string str;

    while (go) {
        std::cout << "\n0: Exit\n1: Change vk\n2: Change mail\n3: Change number\n";
        std::cin >> action;

        switch (action) {
        case 0:
            go = false;
            break;

        case 1:
            std::cout << "Write new vk: ";
            std::cin >> str;
            user->contact_data.setCommunicationData("vk", str);
            break;

        case 2:
            std::cout << "Write new mail: ";
            std::cin >> str;
            user->contact_data.setCommunicationData("mail", str);
            break;

        case 3:
            std::cout << "Write new number: ";
            std::cin >> str;
            user->contact_data.setCommunicationData("number", str);
            break;

        default:
            std::cout << "Error action. Try again.\n";
            break;
        
        }
    }
}


// �������������� ������� *************************************

std::string DeleteTheUnderScore(std::string str) {
    boost::erase_all(str, "_");
    return str;
}

void CreateData(UserData *user, std::set<std::string> logins) {
    std::string str, str2;
    std::set <std::string>::iterator it;
    bool go = true;

    std::cout << "Fill in the fields" << std::endl;
    while (go) {
        std::cout << "login: ";
        std::cin >> str;

        it = logins.find(str);
        if (it == logins.end())
            go = false;
        else
            std::cout << "This password already exists. Try again.\n";
    }
    user->setLogin(str);
    std::cout << "password: ";
    std::cin >> str;
    user->setPassword(str);
    std::cout << "name: ";
    std::cin >> str;
    std::cout << "surname: ";
    std::cin >> str2;

    user->personal_data.setNameSurname(str, str2);
}

void CreateAnotherData(UserData *user) {
    std::string str;
    std::cout << "\nFill in the fields or put dash" << std::endl;

    std::cout << "Some information about you" << std::endl;
    std::cout << "birthday: ";
    std::cin >> str;
    // �������� �������� �� ������������ �������� ������
    user->personal_data.setBirthDate(str);
    std::cout << "About you: ";
    std::cin.get();
    std::getline(std::cin, str);
    user->personal_data.setPersonalInfo(str);
    std::cout << "avatarphoto path: ";
    std::cin >> str;
    user->personal_media.setAvatarPhoto(str);

    std::cout << "\nCommunication data" << std::endl;
    std::cout << "vk: ";
    std::cin >> str;
    user->contact_data.setCommunicationData("vk", str);
    std::cout << "mail: ";
    std::cin >> str;
    user->contact_data.setCommunicationData("mail", str);
    std::cout << "phone number: ";
    std::cin >> str;
    user->contact_data.setCommunicationData("number", str);

    DropdownList list;
    std::cout << "\nChoose musical instrument" << std::endl;
    int action=-1;
    int inst_size = list.getCountInstr();

    while (action != 0) {
        std::cout << "\n0: exit\n";
        for (int i = 0; i < inst_size; i++) {
            std::cout << "\n" << i + 1 << ": " << list.getMusicalInstrument(i) << "\n";
        }
        std::cin >> action;
        if (action != 0 && action<=inst_size) {
            user->personal_music.setMusicalInstruments(list.getMusicalInstrument(action - 1));
        }
    }

    std::cout << "\nChoose musical genre" << std::endl;
    action = -1;
    int genre_size = list.getCountGenre();

    while (action != 0) {
        std::cout << "\n0: exit\n";
        for (int i = 0; i < genre_size; i++) {
            std::cout << "\n" << i + 1 << ": " << list.getMusicalGenre(i) << "\n";
        }
        std::cin >> action;
        if (action != 0 && action <= genre_size) {
            user->personal_music.setMusicalGenres(list.getMusicalGenre(action - 1));
        }
    }

}

void WriteFileOut(std::ofstream&file, UserData* user) {
    file << "id: " << user->getID() << std::endl;
    file << "login: " << user->getLogin() << std::endl;
    file << "password: " << user->getPassword() << std::endl;
    file << "name: " << user->personal_data.getName() << std::endl;
    file << "surname: " << user->personal_data.getSurname() << std::endl;
    file << "birthdate: " << user->personal_data.getBirthDate() << std::endl;
    file << "info: " << user->personal_data.getPersonalInfo() << std::endl;
    file << "avatar: " << user->personal_media.getAvatarPhoto() << std::endl;
    file << "vk " << user->contact_data.getCommunicationData("vk") << std::endl;
    file << "mail " << user->contact_data.getCommunicationData("mail") << std::endl;
    file << "number " << user->contact_data.getCommunicationData("number") << std::endl;
    file << "music:" << user->personal_music.forFileInstr() << user->personal_music.forFileGenre() << std::endl;
    file << "friends: " << user->friends.getFriends();

}

std::string GetLogin(std::string str) {
    //std::vector<std::string> result;
    //boost::split(result, str, boost::is_any_of(" "));
    std::istringstream stream(str);
    std::string result;
    stream >> result;
    stream >> result;
    return result;
}

void TakeDataFromFile(std::ifstream&file, UserData* user) {
    std::string str;
    std::getline(file, str);
    str = str.substr(str.find_first_of(" ") + 1);
    user->setId(boost::lexical_cast<int> (str));

    std::getline(file, str);
    str = str.substr(str.find_first_of(" ") + 1);
    user->setLogin(str);

    std::getline(file, str);
    str = str.substr(str.find_first_of(" ") + 1);
    user->setPassword(str);
    
    std::string str2;
    std::getline(file, str);
    str = str.substr(str.find_first_of(" ") + 1);
    std::getline(file, str2);
    str2 = str2.substr(str2.find_first_of(" ") + 1);
    user->personal_data.setNameSurname(str,str2);

    std::getline(file, str);
    str = str.substr(str.find_first_of(" ") + 1);
    user->personal_data.setBirthDate(str);

    std::getline(file, str);
    str = str.substr(str.find_first_of(" ") + 1);
    user->personal_data.setPersonalInfo(str);

    std::getline(file, str);
    str = str.substr(str.find_first_of(" ") + 1);
    user->personal_media.setAvatarPhoto(str);

    for (int i = 0; i < MEDIA; i++) {
        std::getline(file, str);
        std::istringstream stream(str);
        std::string app, path;
        stream >> app >> path;
        user->contact_data.setCommunicationData(app, path);
    }

    std::getline(file, str);
    str = str.substr(str.find_first_of(" ") + 1);
    std::istringstream in(str);
    std::string substr;
    while (in >> substr) {
        if (CheckI_(substr)) {
            substr = substr.erase(0, 2);
            user->personal_music.setMusicalInstruments(substr);
        }
        else if (CheckG_(substr)) {
            substr = substr.erase(0, 2);
            user->personal_music.setMusicalGenres(substr);
        }
    }
    
    std::getline(file, str);
    str = str.substr(str.find_first_of(" ") + 1);
    if (str != "-") {
        std::regex reg("\\w+");
        std::regex_token_iterator<std::string::iterator> iter(str.begin(), str.end(), reg);
        std::regex_token_iterator<std::string::iterator> end;
        for (; iter != end; ++iter)
            user->friends.setFriend(iter->str());
    }
}

bool CheckI_(std::string str) {
    if (str[0] == 'i'&&str[1] == '_')
        return true;
    return false;
}
bool CheckG_(std::string str) {
    if (str[0] == 'g'&&str[1] == '_')
        return true;
    return false;
}

// ������� ��� ������ � ������ ��� �������������� *************

std::vector<std::string> ReadPersonFile() {
    std::string str;
    std::string filename = "DB\\", f;
    int users_num = 0;

    std::vector<std::string> data;
    UserData* user = new UserData;

    std::ifstream F_PERSON;
    f = filename + "person.txt";
    F_PERSON.open(f);
    if (!F_PERSON.is_open()) {
        std::cout << "\nERR READING FILE" << std::endl;
        return data;
    }

    std::getline(F_PERSON, str);
    users_num = boost::lexical_cast<int> (str);
    if (users_num != 0) {
        while (!F_PERSON.eof()) {
            std::getline(F_PERSON, str);
            data.push_back(str);
        }
    }
    F_PERSON.close();

    return data;
}

void WriteToFile(std::string filename, UserData *user) {
    std::ofstream F_NEWFILE;
    F_NEWFILE.open(filename);
    if (!F_NEWFILE.is_open()) {
        std::cout << "\nERR READING FILE" << std::endl;
        return ;
    }
    else {
        WriteFileOut(F_NEWFILE, user);
    }
    F_NEWFILE.close();
}