#include <iostream>
#include <vector>
#include "Statement.h"
#include "Mamdani.h"

int main() {
    std::vector<float> input_date = {40.f, 10.f};//0 - Age_construct, 1 - quality_construct
    Statement statements(input_date);
    Conclusions conclusion;
    Rules rules;
    Mamdani mamdani(statements, rules, conclusion);
    mamdani.showResult();
}
