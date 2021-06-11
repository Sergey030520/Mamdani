//
// Created by Malip on 11.06.2021.
//

#ifndef MAMDANI_MAMDANI_H
#define MAMDANI_MAMDANI_H

#include <iostream>
#include <vector>
#include "Rule.h"
#include "Conclusion.h"

class Mamdani {
private:
    Conclusions conclusions;
    Statement statements = Statement();
    Rules rules_vector  = Rules();
    float resDefuzzification; std::string resConclusion;
    std::vector<float> aggregation_result;
    void aggregation();
    void defuzzification(const std::vector<float>& values);
    int MaxRules(const std::vector<float>& array);
public:
    std::vector<float> Accumulation();
    Mamdani(Statement &copy_statement, Rules &copy_rules, Conclusions &copy_conclusion);
    const std::vector<float>& getResFuzzificathion(){
        return aggregation_result;
    }
    void showResult(){
        std::cout << "Mamdani: " <<  resConclusion << " " << resDefuzzification << std::endl;
    }
    float  getResult(){
        return resDefuzzification;
    }

};


#endif //MAMDANI_MAMDANI_H
