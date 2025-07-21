#include "minion.h"
#include <fstream>

Minion::Minion(std::string name) {
    readInfo(name);
}

Minion::~Minion() {}

void Minion::readInfo(std::string name) {
    // INPUT FORMAT:
    // cost
    // attack
    // defense

    // OPTIONAL:
    // ability keyword (triggered or activated)
    // ability description
    // ability cost (if activated)

    std::string file{"./minions/" + name + ".txt"};
    std::ifstream in{file};

    this->name = name;
    in >> cost;
    in >> attack;
    in >> defense;
}

void Minion::doDamage(Minion &m) {
    m.takeDamage(attack);
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
