#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "collection.h"
#include "deck.h"
#include "hand.h"
//#include "graveyard.h"

class Player {
    int health;
    int mana;
    Deck deck;
    Hand hand;
public:

    Player(int hp, int mp) {}

    ~Player() = default;

    void createDeck() {}

    // returns false if the player doesn't die and true if they do
    bool takeDamage(int dmg) {}

    size_t getHandSize() {}

    Hand &getHand() {}

    Deck &getDeck() {}

};

#endif
