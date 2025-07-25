#include "ritual.h"
#include <fstream>

const std::string DIRECTORY = "./rituals/";
const std::string EXTENSION = ".txt";

Ritual::Ritual(std::string name, Player &player): Card{player} {
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
    in.ignore();
    std::getline(in, abilityDesc);
    abilityFunc = am->getAbility(name);
    
    std::string temp;
    in >> temp;
    triggerType = convertToTriggerType(temp);
}

void Ritual::useAbility(Game &game) {
    if (getDefense() >= getAbilityCost()) {
        abilityFunc(game);
        setDefense(getDefense() - getAbilityCost());
    }
}

CardType Ritual::getType() { return CardType::Ritual; }
