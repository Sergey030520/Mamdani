//
// Created by Malip on 11.06.2021.
//

#ifndef MAMDANI_CONCLUSION_H
#define MAMDANI_CONCLUSION_H
#include <fstream>
#include <vector>
#include "Term.h"
#include "UniverseFuzzyVariables.h"
#include "StringOperation.h"
#include "Variable.h"


class Conclusions{
private:
    std::vector<Variable> variables;
public:
    Conclusions(){
        StringOperation stringOp;
        std::ifstream condition(R"(C:\Users\Malip\source\repos\Mamdani\Data\Conclusion.txt)", std::ios::app);
        for ( int ind = -1; !condition.eof();){
            std::string nameVar, nameLine, unnecessary_var, maxRange, minRange;
            condition >>  nameLine >> nameVar >> unnecessary_var >> minRange >> unnecessary_var >> maxRange;
            if (nameLine == "Name:"){
                float startRange = (stringOp.isDigitalString(minRange) ? std::stof(minRange) : variables[ind].getUnFuzzyVar().getStart()),
                        endRange = (stringOp.isDigitalString(maxRange) ? std::stof(maxRange) : variables[ind].getUnFuzzyVar().getEnd());
                variables[ind].setTerms(Term( stringOp.tolower(nameVar), FuzzySet(startRange, endRange)));
            }
            if (nameLine == "Class:") {
                variables.emplace_back( stringOp.tolower(nameVar), UniverseFuzzyVariables(std::stof(minRange),
                                                                                          std::stof(maxRange)));
                ++ind;
            }
        }
        condition.close();
    }
    Variable getVariable(int numb){
        return variables[numb];
    }
    int getCountVariable(){
        return variables.size();
    }
    int find(const std::string& name){
        for (int ind = 0; ind < variables.size(); ++ind) {
            if (name == variables[ind].getName()) return ind;
        }
        return -1;
    }
    std::vector<float> getResOwnershipTerm(int numbVar, std::string nameTerm, float value){
        std::vector<float> res;
        Term term = variables[numbVar].getTerms(variables[numbVar].find(nameTerm));
        Variable variable = variables[numbVar];
        if (term.getFuzzySet().getStart() == variable.getUnFuzzyVar().getStart()){
            res.emplace_back((-1)*(term.getFuzzySet().getEnd() - term.getFuzzySet().getStart())*(value - 1)
                             + term.getFuzzySet().getStart());
        }else if (term.getFuzzySet().getEnd() == variable.getUnFuzzyVar().getEnd()){
            res.emplace_back((term.getFuzzySet().getEnd() - term.getFuzzySet().getStart())*(value - 1)
                             + term.getFuzzySet().getEnd());
        }else{
            float middle = term.getFuzzySet().getStart() + ((term.getFuzzySet().getEnd() - term.getFuzzySet().getStart())/2);
            res.emplace_back((-1)*(term.getFuzzySet().getEnd() - middle)*(value - 1)
                             + middle);
            res.emplace_back((middle - term.getFuzzySet().getStart())*(value - 1)
                             + term.getFuzzySet().getEnd());
        }
        return res;
    }
};
#endif //MAMDANI_CONCLUSION_H
