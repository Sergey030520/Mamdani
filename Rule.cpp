//
// Created by Malip on 11.06.2021.
//

#include <fstream>
#include "Rule.h"

enum Records{
    STOP,
    START_CONDITIONS,
    START_CONCLUSION
};
void Rules::correctly_dateFile() {
    std::ifstream file(R"(C:\Users\Malip\source\repos\Mamdani\Data\DataRule.txt)", std::ios::in);
    std::string text;
    std::string word;
    StringOperation stringOp;
    while (!file.eof()){
        char ruleStr[255];
        file.read(ruleStr, sizeof (ruleStr) - 1);
        for (int ind = 0; ind < file.gcount() && ruleStr[ind] != '\0'; ++ind) {
            if (ruleStr[ind] == ' ' || ruleStr[ind] == '\n') {
                word = stringOp.tolower(word);
                if (word == "if" || word == "then" || word == "and" || word == "or") word = stringOp.toupper(word);
                else if(word == "||") word = "OR";
                else if(word == "&&") word = "AND";
                text += (word + ruleStr[ind]);
                word.clear();
            }
            else word += ruleStr[ind];
        }
    }
    text += word;
    file.close();
    std::ofstream record_file(R"(C:\Users\Malip\source\repos\Mamdani_Sugeno\DataRule.txt)");
    record_file.write(text.c_str(), sizeof(char) * text.size());
    record_file.close();
}
Rules::Rules(){
    correctly_dateFile();
    std::ifstream file(R"(C:\Users\Malip\source\repos\Mamdani\Data\DataRule.txt)", std::ios::app);
    std::string ruleStr;
    StringOperation stringOp;
    for (int record = STOP, numbRule = -1; !file.eof();){
        file >> ruleStr;
        if (ruleStr == "IF") {
            rules.emplace_back(Rule());
            ++numbRule;
            record = START_CONDITIONS;
        }
        else if(ruleStr == "THEN") {
            record = START_CONCLUSION;
        }
        if (ruleStr == "AND" || ruleStr == "OR"  || ruleStr == "||" || ruleStr == "&&")
            rules[numbRule].addLogicVar(ruleStr);
        else if (record == START_CONDITIONS){
            std::string nameVar, symbol, nameCond;
            if (ruleStr == "IF") {
                file >> nameVar >> symbol >> nameCond;
            }else{
                nameVar = ruleStr;
                file >> symbol >> nameCond;
            }
            nameVar = stringOp.strip(nameVar), nameCond = stringOp.strip(nameCond);
            rules[numbRule].addConditions(Conditions(&nameVar, &nameCond));
        }else {
            std::string nameCond, weight;
            file >> nameCond >> weight;
            rules[numbRule].addConclusion(Conclusion(&nameCond, std::stof(stringOp.strip(weight))));
        }
    }
    file.close();
}

bool Rules::identical_logical(const int &numbRules) {
    for (int ind = 1; ind < rules[numbRules].getCountLogicVar(); ++ind) {
        if (rules[numbRules].getLogicVar(ind) != rules[numbRules].getLogicVar(ind--)) return false;
    }
    return true;
}
