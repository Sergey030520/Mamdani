//
// Created by Malip on 11.06.2021.
//

#ifndef MAMDANI_FUZZYSET_H
#define MAMDANI_FUZZYSET_H

struct FuzzySet{
private:
    float leftX = 0, rightX = 0;
public:
    FuzzySet(){}
    FuzzySet(float copy_start, float copy_end){
        if (copy_start  < copy_end) leftX = copy_start, rightX = copy_end;
        else leftX = copy_end, rightX = copy_start;
    }
    float getStart(){
        return leftX;
    }
    float getEnd(){
        return rightX;
    }
};
#endif //MAMDANI_FUZZYSET_H
