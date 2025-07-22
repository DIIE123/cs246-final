#ifndef RITUAL_H
#define RITUAL_H

#include <string>
#include "card.h"

class Ritual: public Card {
    int charges;
    int abilityCost;

    void readInfo(std::string name) override;

public:
    Ritual(std::string name);
};

#endif
