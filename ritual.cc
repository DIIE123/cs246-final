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
    // ability description
    // ability cost

    std::string file{DIRECTORY + name + EXTENSION};
    std::ifstream in{file};

    this->name = name;
    in >> cost;
    in >> charges;
    in >> abilityDesc;
    abilityFunc = am->getAbility(name);
    in >> abilityCost;
}

CardType Ritual::getType() { return CardType::Ritual; }
