//
// Created by Malip on 11.06.2021.
//

#ifndef MAMDANI_STRINGOPERATION_H
#define MAMDANI_STRINGOPERATION_H


#include <string>

class StringOperation {
public:
    std::string tolower(const std::string&);
    std::string toupper(const std::string &);
    std::string strip(const std::string&);
    bool isDigitalString(std::string word);
};


#endif //MAMDANI_STRINGOPERATION_H
