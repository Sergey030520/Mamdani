//
// Created by Malip on 11.06.2021.
//

#ifndef MAMDANI_RULE_H
#define MAMDANI_RULE_H


#include <string>
#include <vector>
#include <iostream>
#include "Statement.h"
#include "StringOperation.h"

struct Conditions{
private:
    std::string nameVar, nameCondition;
    float weight = 1;
public:
    Conditions(const std::string* copyNameVar, const std::string* copyNameCond, const float& copy_weight){
        weight = (copy_weight < 1 && copy_weight >= 0 ? copy_weight : (copy_weight == 0.0f ? 0.0f : 1.0f));
        nameVar = *copyNameVar, nameCondition = *copyNameCond;
    }
    Conditions(const std::string* copyNameVar, const std::string* copyNameCond){
        nameVar = *copyNameVar, nameCondition = *copyNameCond;
    }
    std::string getNameVar(){
        return nameVar;
    }
    std::string getNameCondition(){
        return nameCondition;
    }
};
struct Conclusion{
private:
    std::string nameCondition;
    std::vector<Term> terms;
    float weight;
public:
    Conclusion(const std::string* copyNameCondition, const float& copy_weight){
        nameCondition = *copyNameCondition,
                weight = (copy_weight < 1 && copy_weight >= 0 ? copy_weight : (copy_weight == 0.0f ? 0.0f : 1.0f));
    }
    std::string getNameCondition(){
        return nameCondition;
    }
    float getWeight(){
        return weight;
    }
};

struct Rule{
private:
    std::vector<Conditions> conditions;
    std::vector<Conclusion> conclusion;
    std::vector<std::string> logicVar;
public:
    void addLogicVar(const std::string& copy_logicVar){ logicVar.emplace_back(copy_logicVar);}
    void addConclusion(const Conclusion& copy_conclusion){ conclusion.emplace_back(copy_conclusion);}
    void addConditions(const Conditions& copy_conditions) {conditions.emplace_back(copy_conditions);}
    Conditions getCondition(int numb){
        return conditions[numb];
    }
    Conclusion getConclusion(int numb){
        return conclusion[numb];
    }
    std::string getLogicVar(int numb){
        return logicVar[numb];
    }
    int getCountCondition(){
        return conditions.size();
    }
    int getCountConclusion(){
        return conclusion.size();
    }
    int getCountLogicVar(){
        return logicVar.size();
    }
};

class Rules{
private:
    std::vector<Rule> rules;
public:
    Rules();
    void correctly_dateFile();
    bool identical_logical(const int&);
    Rule getRule(int numb){
        return rules[numb];
    }
    int getCountRules(){
        return rules.size();
    }
};


#endif //MAMDANI_RULE_H
