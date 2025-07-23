#include "minion.h"
#include "player.h"
#include <fstream>

const std::string DIRECTORY = "./minions/";
const std::string EXTENSION = ".txt";

Minion::Minion(std::string name, Player &owner, Player &opponent): owner{owner}, opponent{opponent} {
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
    in >> input;
    ability = am->getAbility(input);

    if (input == "trigger") {
        // Read trigger type
        in >> triggerType;
    }
    else if (input == "active") {
        // Read active cost
        in >> abilityCost;
    }
}

// TODO: Make minion use the methods getAttack, getDefense, etc. so it uses the enchanted versions

void Minion::doDamage(Minion &other) {
    other.takeDamage(attack);
}

void Minion::doDamage(Player &player) {
    player.takeDamage(attack);
}

void Minion::takeDamage(int damage) {
    defense -= damage;
}

void Minion::decreaseActions() {
    --actions;
}

void Minion::resetActions() {
    actions = maxActions;
}

bool Minion::isDead() const {
    return defense <= 0;
}

// Getters
int Minion::getAttack() { return attack; }
int Minion::getDefense() { return defense; }
int Minion::getActions() { return actions; }
int Minion::getMaxActions() { return maxActions; }
int Minion::getAbilityCost() { return abilityCost; }
std::string Minion::getType() { return "minion"; }
