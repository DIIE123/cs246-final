#include "minion.h"
#include <fstream>

const std::string DIRECTORY = "./minions/";
const std::string EXTENSION = ".txt";

Minion::Minion(std::string name) {
    readInfo(name);
}

void Minion::readInfo(std::string name) {
    // INPUT FORMAT:
    // cost
    // attack
    // defense

    // OPTIONAL:
    // ability keyword (trigger or active)
    // ability description
    // ability cost (if activated) or type of trigger (if triggered)

    std::string file{DIRECTORY + name + EXTENSION};
    std::ifstream in{file};

    this->name = name;

    // Read cost, attack, defense
    if (!(in >> cost >> attack >> defense)) return;

    // Read type
    std::string input;
    in >> input;

    // Read ability
    in >> abilityDesc;
    abilityFunc = am->getAbility(name);

    if (input == "trigger") {
        // Read trigger type
        in >> input;
        triggerType = convertToTriggerType(input);
    }
    else if (input == "active") {
        // Read active cost
        in >> abilityCost;
    }
}

// Getters
CardType Minion::getType() { return CardType::Minion; }
