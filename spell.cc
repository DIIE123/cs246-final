#include "spell.h"
#include <fstream>

const std::string DIRECTORY = "./spells/";
const std::string EXTENSION = ".txt";

Spell::Spell(std::string name, Player &player): Card{player} {
    readInfo(name);
}

void Spell::readInfo(std::string name) {
    // INPUT FORMAT:
    // cost
    // ability description
    // type (target or use)

    std::string file{DIRECTORY + name + EXTENSION};
    std::ifstream in{file};

    this->name = name;
    in >> cost;
    in.ignore();
    std::getline(in, abilityDesc);
    abilityFunc = am->getAbility(name);
    std::string temp;
    in >> temp;
    if (temp == "target") isTarget = true;
    else isTarget = false;
}

CardType Spell::getType() { return CardType::Spell; }
