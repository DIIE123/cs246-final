#include "card.h"
#include <iostream>

Card::Card(): cost{5} {}
Card::Card(std::string name, size_t cost): name{name}, cost{cost} {}
Card::~Card() {}

std::string Card::getName() {
    return name;
}

size_t Card::getCost() {
    return cost;
}

void Card::useAbility(Player *player, Minion *minion) {
    ability->useAbility(player, minion);
}

