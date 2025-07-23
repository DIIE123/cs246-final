#include "card.h"
#include <iostream>

std::unique_ptr<AbilityManager> Card::am = std::make_unique<AbilityManager>();

Card::Card() {}
Card::~Card() {}

std::string Card::getName() {
    return name;
}

int Card::getCost() {
    return cost;
}

// void Card::useAbility(Player *player, Minion *minion) {
//     ability->useAbility(player, minion);
// }

