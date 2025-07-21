#include "card.h"
#include "minion.h"
#include <iostream>

// Testing
int main() {
    Minion minion = Minion{"Air Elemental"};
    std::cout << minion.getCost() << std::endl;
}

