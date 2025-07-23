#include "card.h"
#include <iostream>

Card::Card(): cost{5} {}
Card::~Card() {}

std::string Card::getName() {
    return name;
}

size_t Card::getCost() {
    return cost;
}

std::string Card::getAbilityDesc() {
    return abilityDesc;
}

void Card::useAbility(Game &game) {
    abilityFunc(game);
}

