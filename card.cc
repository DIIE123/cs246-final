#include "card.h"

Card::Card() {}
Card::~Card() {}

std::string Card::getName() {
    return name;
}

int Card::getCost() {
    return cost;
}
