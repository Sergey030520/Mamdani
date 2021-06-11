//
// Created by Malip on 11.06.2021.
//

#ifndef MAMDANI_UNIVERSEFUZZYVARIABLES_H
#define MAMDANI_UNIVERSEFUZZYVARIABLES_H
struct UniverseFuzzyVariables{
private:
    float leftX = 0, rightX = 0;
public:
    UniverseFuzzyVariables(const float&  copyX, const float& copyY){
        if (copyX > copyY) leftX = copyY, rightX = copyX;
        else leftX = copyX, rightX = copyY;
    }
    float getEnd() const{ return rightX;}
    float getStart() const{return leftX;}
};

#endif //MAMDANI_UNIVERSEFUZZYVARIABLES_H
