//
// Created by Malip on 11.06.2021.
//

#include <iostream>
#include "Statement.h"


Statement::Statement(const std::vector<float>& values){
    std::ifstream condition(R"(C:\Users\Malip\source\repos\Mamdani\Data\Condition.txt)", std::ios::app);
    StringOperation stringOp;
    for ( int ind = -1; !condition.eof();){
        std::string nameVar, nameLine, unnecessary_var, maxRange, minRange;
        condition >>  nameLine >> nameVar >> unnecessary_var >> minRange >> unnecessary_var >> maxRange;
        if (nameLine == "Name:"){
            float startRange = (stringOp.isDigitalString(minRange) ? std::stof(minRange) : variables[ind].getUnFuzzyVar().getStart()),
                    endRange = (stringOp.isDigitalString(maxRange) ? std::stof(maxRange) : variables[ind].getUnFuzzyVar().getEnd());
            variables[ind].setTerms(Term( stringOp.tolower(nameVar), FuzzySet(startRange, endRange),
                                          values[ind], variables[ind].getUnFuzzyVar()));
        }
        if (nameLine == "Class:") {
            variables.emplace_back( stringOp.tolower(nameVar), UniverseFuzzyVariables(std::stof(minRange),
                                                                                      std::stof(maxRange)));
            ++ind;
        }
    }
    condition.close();
}

int  Statement::IndexVariable(const std::string& nameVar) {
    for (int numbVar = 0; numbVar < variables.size(); ++numbVar) {
        if ( variables[numbVar].getName() == nameVar) return numbVar;
    }
}

Statement::Statement() = default;
