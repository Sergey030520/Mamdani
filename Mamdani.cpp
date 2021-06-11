//
// Created by Malip on 11.06.2021.
//


#include "Mamdani.h"



void Mamdani::aggregation() {
    for (int numbRules = 0; numbRules < rules_vector.getCountRules(); ++numbRules) {
        if (rules_vector.getRule(numbRules).getCountLogicVar() > 0){
            if (rules_vector.identical_logical(numbRules)){
                if (rules_vector.getRule(numbRules).getLogicVar(0) == "AND"){
                    float weightMin = 1;
                    for (int numbVar = 0; numbVar < rules_vector.getRule(numbRules).getCountCondition(); ++numbVar) {
                        float copy_weight = statements.getVariable(statements.IndexVariable(
                                rules_vector.getRule(numbRules).getCondition(numbVar).getNameVar()
                        )).getWeightTerm(rules_vector.getRule(numbRules).getCondition(numbVar).getNameCondition());
                        if (weightMin > copy_weight) weightMin = copy_weight;
                    }
                    aggregation_result.emplace_back(weightMin);
                }
                else{
                    float weightMax = 0;
                    for (int numbVar = 0; numbVar < rules_vector.getRule(numbRules).getCountCondition(); ++numbVar) {
                        float copy_weight = statements.getVariable(
                                statements.IndexVariable(rules_vector.getRule(numbRules).getCondition(numbVar).getNameVar())).getWeightTerm(
                                rules_vector.getRule(numbRules).getCondition(numbVar).getNameCondition());
                        if (weightMax < copy_weight) weightMax = copy_weight;
                    }
                    aggregation_result.emplace_back(weightMax);
                }
            } else{
                /*Если разные знаки*/
            }
        }
        else{
            aggregation_result.emplace_back(statements.getVariable(
                    statements.IndexVariable(rules_vector.getRule(numbRules).getCondition(0).getNameVar())).getWeightTerm(
                    rules_vector.getRule(numbRules).getCondition(0).getNameCondition()));
        }
    }
}

Mamdani::Mamdani(Statement& copy_statement, Rules& copy_rules, Conclusions& copy_conclusion) {
    conclusions = copy_conclusion;
    rules_vector = copy_rules;
    statements = copy_statement;
    aggregation();
    defuzzification(Accumulation());
    float maxWeight = 0;
    for (int indTerm = 0; indTerm < conclusions.getVariable(0).getCountTerms(); ++indTerm) {
        std::string nameCondition = conclusions.getVariable(0).getTerms(indTerm).getName();
        float termWeight = conclusions.getVariable(0).getTerms(indTerm).ownership_terms_triangle(resDefuzzification);
        if (maxWeight < termWeight){
            maxWeight = termWeight;
            resConclusion = nameCondition;
        }
    }
}

std::vector<float> Mamdani::Accumulation() {
    int indRuleMax = MaxRules(aggregation_result);
    resConclusion = rules_vector.getRule(indRuleMax).getConclusion(0).getNameCondition();
    return conclusions.getResOwnershipTerm(0, resConclusion,aggregation_result[indRuleMax]);
}

int Mamdani::MaxRules(const std::vector<float>& array) {
    float max = -10000;
    int indRule = -1;
    for (int ind = 0; ind < array.size(); ++ind) {
        if (max < array[ind]){
            indRule = ind;
            max = array[ind];
        }
    }
    return indRule;
}

void Mamdani::defuzzification(const std::vector<float>& values) {
    for (int ind = 0; ind < values.size(); ++ind) {
        resDefuzzification += values[ind];
    }
    resDefuzzification /= values.size();
}