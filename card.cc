#include "card.h"
#include <iostream>

Card::Card() {}
Card::~Card() {}

std::string Card::getName() {
    return name;
}

int Card::getCost() {
    return cost;
}

void Card::useAbility(Player *player, Minion *minion) {
    ability->useAbility(player, minion);
}

