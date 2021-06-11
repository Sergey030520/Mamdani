//
// Created by Malip on 11.06.2021.
//

#include "StringOperation.h"


std::string StringOperation::tolower(const std::string & word) {
    std::string new_word;
    for (int ind = 0; ind < word.size(); ++ind){
        new_word += (char)std::tolower(word[ind]);
    }
    return new_word;
};
std::string StringOperation::toupper(const std::string & word) {
    std::string new_word;
    for (int ind = 0; ind < word.size(); ++ind){
        new_word += (char)std::toupper(word[ind]);
    }
    return new_word;
}

std::string StringOperation::strip(const std::string & word) {
    std::string new_word;
    for (int ind = 0; ind < word.size(); ++ind) {
        if (word[ind] != '(' && word[ind] != ')') new_word += word[ind];
    }
    return new_word;
}

bool StringOperation::isDigitalString(std::string word) {
    for (int ind = 0; ind < word.length(); ++ind) if (isdigit(word[ind]) == 0) return false;
    return true;
};