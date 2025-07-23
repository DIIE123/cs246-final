#include "minion.h"
#include "player.h"
#include <fstream>

const std::string DIRECTORY = "./minions/";
const std::string EXTENSION = ".txt";

Minion::Minion(std::string name) {
    readInfo(name);
}

Minion::Minion(std::string name, size_t cost): Card{name, cost} {}

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
        in >> triggerType;
    }
    else if (input == "active") {
        // Read active cost
        in >> abilityCost;
    }
}

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
CardType Minion::getType() { return CardType::Minion; }

// Setters
void Minion::setAttack(int attack) { this->attack = attack; }
void Minion::setDefense(int defense) { this->defense = defense; }
void Minion::setMaxActions(int maxActions) { this->maxActions = maxActions; }
void Minion::setActions(int actions) { this->actions = actions; }
void Minion::setAbilityCost(int abilityCost) { this->abilityCost = abilityCost; }
