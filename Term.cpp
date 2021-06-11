//
// Created by Malip on 11.06.2021.
//

#include <vector>
#include <iostream>
#include "Term.h"



bool Term::compare(float number1, float number2, float epsilon = 0.01) {
    return ((number1 <= number2 + epsilon) && (number1 >= number2 - epsilon));
}
float Term::ownership_terms_triangle(const float& value){
    float middle = Middle(std::vector<float>() = {fuzzySet.getStart(), fuzzySet.getEnd()});
    if(value <= fuzzySet.getStart()){
        return 0;
    }else if(fuzzySet.getStart() <= value && value <= middle){
        return (value - fuzzySet.getStart())/(middle  - fuzzySet.getStart());
    }
    else if (middle <= value && value <= fuzzySet.getEnd()){
        return (fuzzySet.getEnd() - value)/(fuzzySet.getEnd()-middle);
    }else{
        return 0;
    }
}
float Term::ownership_terms(const float& value) {
    if (value < fuzzySet.getStart() ||value > fuzzySet.getEnd()) return 0;
    else if(compare(unFuzzyVar.getStart(), fuzzySet.getStart())){
        float  middle = Middle( std::vector<float>()={fuzzySet.getStart(), fuzzySet.getEnd()});
        if(fuzzySet.getStart() <= value && middle >= value){
            return 1;
        }else if(middle < value && value <= fuzzySet.getEnd()){
            return (1 - ((value - middle)/(fuzzySet.getEnd() - middle)));;
        }
    }else if(compare(unFuzzyVar.getEnd(), fuzzySet.getEnd())){
        float middle = Middle(std::vector<float>() = {fuzzySet.getStart(), fuzzySet.getEnd()});
        if (fuzzySet.getStart() <= value && value < middle){
            return (1 - ((middle - value)/(middle - fuzzySet.getStart())));
        }else if(middle <= value && value <= unFuzzyVar.getEnd()){
            return 1;
        }
    }else{
        float middle = Middle(std::vector<float>() = {fuzzySet.getStart(), fuzzySet.getEnd()});
        float middleLeft = Middle(std::vector<float>() = {fuzzySet.getStart(), middle}),
                middleRight = Middle(std::vector<float>() = {middle, fuzzySet.getEnd()});
        if (fuzzySet.getStart() <= value && middleLeft > value){
            return (1 - ((middleLeft - value)/(middleLeft - fuzzySet.getStart())));
        }else if(middleLeft <= value && middleRight >= value){
            return 1;
        }else{
            return (1 - ((value - middleRight)/(fuzzySet.getEnd() - middleRight)));
        }
    }
    return 0;
}
Term::Term(const std::string & nameCopy, const FuzzySet & fuzzySetCopy, const float & value,
           const UniverseFuzzyVariables& unFuzzyVarCopy) {
    name = nameCopy;
    fuzzySet = fuzzySetCopy;
    unFuzzyVar = unFuzzyVarCopy;
    weight = ownership_terms(value);
    std::cout << name <<  ": " << weight << std::endl;
}
Term::Term(const std::string &copyName, const FuzzySet &copyFuzzySet) {
    name = copyName;
    fuzzySet = copyFuzzySet;
    weight = -1;
}

float Term::getWeight() {
    return weight;
}

float Term::Middle(const std::vector<float>& numbers){
    float res = 0.f;
    for (int numbCount = 0; numbCount < numbers.size(); ++numbCount) {
        res += numbers[numbCount];
    }
    return res/numbers.size();
}