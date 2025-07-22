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
    // ability keyword (triggered or activated)
    // ability description
    // ability cost (if activated) or type of trigger (if triggered)

    std::string file{DIRECTORY + name + EXTENSION};
    std::ifstream in{file};

    this->name = name;
    if (!(in >> cost >> attack >> defense)) return;

    // std::string temp;
    // in >> temp;
    // if (temp == "triggered") {

    // }
    // else if (temp == "activated") {

    // }
}

void Minion::doDamage(Minion &other) {
    other.takeDamage(attack);
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
