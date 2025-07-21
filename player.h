#ifndef PLAYER_H
#define PLAYER_H

#include "collection.h"
#include "deck.h"

class Player {
    int health;
    int mana;
    Deck deck;
public:

    Player() {}

    ~Player() {}

    void createDeck() {}

    void takeDamage(int dmg) {}

    int getHandSize() {}

    Deck &getDeck() {}

};

#endif
