#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include "collection.h"
#include "deck.h"
#include "hand.h"
//#include "graveyard.h"
#include "card.h"
#include "minion.h"

class Player {
    std::string name;
    int health;
    int mana;
    Deck deck;
    Hand hand;
    std::vector<std::unique_ptr<Card>> activeMinions;
public:

    Player(std::string name, int hp, int mp, std::string deckFile);

    ~Player() = default;

    void playCard(size_t i);

    // returns false if the player doesn't die and true if they do
    bool takeDamage(int dmg);

    size_t getActiveMinions();

    size_t getHandSize();

    Hand &getHand();

    Deck &getDeck();

};

#endif
