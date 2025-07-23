#include "card.h"
#include "player.h"
#include <iostream>
#include <memory>

std::unique_ptr<AbilityManager> Card::am = std::make_unique<AbilityManager>();

Card::Card() {}
Card::~Card() {}

void Card::useAbility(Game &game) {
    abilityFunc(game);
}

// Utilities
void Card::takeDamage(int damage) {
    defense -= damage;
}

void Card::doDamage(Card &other) {
    other.takeDamage(attack);
    takeDamage(other.attack);
}

void Card::doDamage(Player &player) {
    player.takeDamage(attack);
}

void Card::decreaseActions() {
    --actions;
}

void Card::resetActions() {
    actions = maxActions;
}

bool Card::isDead() const {
    return defense <= 0;
}

// Getters
std::string Card::getName() { return name; }
size_t Card::getCost() { return cost; }
std::string Card::getAbilityDesc() { return abilityDesc; }
int Card::getAbilityCost() { return abilityCost; }
int Card::getAttack() { return attack; }
int Card::getDefense() { return defense; }
int Card::getActions() { return actions; }
int Card::getMaxActions() { return maxActions; }

// Setters
void Card::setAttack(int attack) { this->attack = attack; }
void Card::setDefense(int defense) { this->defense = defense; }
void Card::setMaxActions(int maxActions) { this->maxActions = maxActions; }
void Card::setActions(int actions) { this->actions = actions; }
void Card::setAbilityCost(int abilityCost) { this->abilityCost = abilityCost; }
