//
// Created by Malip on 11.06.2021.
//

#ifndef MAMDANI_STATEMENT_H
#define MAMDANI_STATEMENT_H


#include <vector>
#include <fstream>
#include "FuzzySet.h"
#include "UniverseFuzzyVariables.h"
#include "Variable.h"
#include "StringOperation.h"

class Statement {
private:
    std::vector <Variable> variables;
public:
    Statement();
    Statement(const std::vector<float>& values);
    Variable &getVariable(int numb) {
        return variables[numb];
    }
    int getCountVariable(){
        return variables.size();
    }
    int IndexVariable(const std::string& nameVar);
};


#endif //MAMDANI_STATEMENT_H
