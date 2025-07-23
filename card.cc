#include "card.h"
#include <iostream>
#include <memory>

std::unique_ptr<AbilityManager> Card::am = std::make_unique<AbilityManager>();

Card::Card() {}
Card::~Card() {}

void Card::useAbility(Game &game) {
    abilityFunc(game);
}

std::string Card::getName() {
    return name;
}

size_t Card::getCost() {
    return cost;
}

std::string Card::getAbilityDesc() {
    return abilityDesc;
}

