#ifndef SPELL_H
#define SPELL_H

#include <string>
#include "card.h"

class Spell: public Card {
    void readInfo(std::string name) override;

public:
    Spell(std::string name, Player &player);
    CardType getType() override;
};

#endif
