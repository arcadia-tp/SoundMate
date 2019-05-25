#ifndef SEARCHDATA_H_
#define SEARCHDATA_H_

#include <vector>
#include <cstring>

std::vector<std::string> Parser(std::string str);
std::vector<std::string> GetInstrumentsFromStr(std::string str);
std::vector<std::string> GetGenresFromStr(std::string str);
std::string GetIdFromSearch(std::string str_search, std::string type_search);

#endif // SEARCHDATA_H_