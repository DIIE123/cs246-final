#include "ritual.h"
#include <fstream>

const std::string DIRECTORY = "./rituals/";
const std::string EXTENSION = ".txt";

Ritual::Ritual(std::string name) {
    readInfo(name);
}

void Ritual::readInfo(std::string name) {
    // INPUT FORMAT:
    // cost
    // charges
    // ability cost
    // ability description
    // trigger type

    std::string file{DIRECTORY + name + EXTENSION};
    std::ifstream in{file};

    this->name = name;
    in >> cost;
    in >> defense;
    in >> abilityCost;
    getline(in, abilityDesc);
    abilityFunc = am->getAbility(name);
    
    std::string temp;
    in >> temp;
    triggerType = convertToTriggerType(temp);
}

CardType Ritual::getType() { return CardType::Ritual; }
