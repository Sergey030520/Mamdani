//
// Created by Malip on 11.06.2021.
//

#ifndef MAMDANI_VARIABLE_H
#define MAMDANI_VARIABLE_H
#include "Term.h"

struct Variable{
private:
    std::string name;
    UniverseFuzzyVariables unFuzzyVar = UniverseFuzzyVariables(0, 0);
    std::vector<Term> terms = {};
public:
    Variable(const std::string& copy_name,  const UniverseFuzzyVariables& copyUnFuzzyVar){
        name = copy_name;
        unFuzzyVar = copyUnFuzzyVar;
    }
    void setTerms(const Term& copy_term){
        terms.emplace_back(copy_term);
    }
    std::string getName(){
        return name;
    }
    UniverseFuzzyVariables getUnFuzzyVar(){
        return unFuzzyVar;
    };
    int find(std::string nameTerm){
        for (int ind = 0; ind < terms.size(); ++ind) {
            if(terms[ind].getName() == nameTerm) return ind;
        }
        return 0;
    }
    Term getTerms(int numb){
        return terms[numb];
    }
    int getCountTerms(){
        return terms.size();
    }
    float getWeightTerm(const std::string& name_cond){
        for (int numbTerm = 0; numbTerm < terms.size(); ++numbTerm) {
            if (terms[numbTerm].getName() == name_cond) return terms[numbTerm].getWeight();
        }
        return 0;
    }
};

#endif //MAMDANI_VARIABLE_H
