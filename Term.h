//
// Created by Malip on 11.06.2021.
//

#ifndef MAMDANI_TERM_H
#define MAMDANI_TERM_H


#include <string>
#include "FuzzySet.h"
#include "UniverseFuzzyVariables.h"


class Term {
private:
    UniverseFuzzyVariables unFuzzyVar = UniverseFuzzyVariables(0, 0);
    std::string name;
    FuzzySet fuzzySet;
    float weight;
    float Middle(const std::vector<float>& numbers);
    bool compare(float,  float , float );
    float ownership_terms(const float&);
public:
    Term(const std::string& , const FuzzySet& , const float&, const  UniverseFuzzyVariables&);
    Term(const std::string& , const FuzzySet& );
    std::string getName() { return name; }
    FuzzySet getFuzzySet() { return fuzzySet; }
    float ownership_terms_triangle(const float&);
    float getWeight();
};



#endif //MAMDANI_TERM_H
