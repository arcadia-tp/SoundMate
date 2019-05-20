#ifndef STRIP_STRING_HPP
#define STRIP_STRING_HPP

#include <string>

void StripString(std::string &mystr) { //separate file
    size_t index = 0;
    while((index = mystr.find(' ')) != std::string::npos)
        mystr.erase(index, 1);
}

#endif
