#ifndef RITUAL_H
#define RITUAL_H

#include <string>
#include "card.h"

class Ritual: public Card {
    void readInfo(std::string name) override;

public:
    Ritual(std::string name, Player &player);
    bool useAbility(Game &game) override;
    CardType getType() override;
};

#endif
