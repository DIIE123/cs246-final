#ifndef SPELL_H
#define SPELL_H

#include <string>
#include "card.h"

class Spell: public Card {
    void readInfo(std::string name);

public:
    Spell(std::string name);
};

#endif
