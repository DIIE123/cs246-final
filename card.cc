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

