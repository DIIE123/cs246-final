#ifndef MINION_H
#define MINION_H

#include <string>
#include "card.h"

class Minion: public Card {
    void readInfo(std::string name) override;

public:
    Minion(std::string name, Player &player);

    // Getters
    virtual CardType getType() override;
};

#endif
