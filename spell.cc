#include "spell.h"
#include <fstream>

const std::string DIRECTORY = "./spells/";
const std::string EXTENSION = ".txt";

Spell::Spell(std::string name) {
    readInfo(name);
}

CardType Spell::getType() {
  return CardType::Spell;
}

void Spell::readInfo(std::string name) {
    // INPUT FORMAT:
    // cost
    // ability description

    std::string file{DIRECTORY + name + EXTENSION};
    std::ifstream in{file};

    this->name = name;
    in >> cost;

    std::string abilityDesc;
    in >> abilityDesc;
    // ability = am->getAbility(abilityDesc);
}
