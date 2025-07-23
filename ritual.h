#ifndef RITUAL_H
#define RITUAL_H

#include <string>
#include "card.h"

class Ritual: public Card {
    void readInfo(std::string name) override;

public:
    Ritual(std::string name);
    CardType getType() override;
};

#endif
