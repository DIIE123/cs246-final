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
#include "activeminions.h"
#include "type.h"
#include "ritual.h"

class Player {
    std::string name;
    int health;
    int mana;
    Deck deck;
    Hand hand;
    ActiveMinions activeMinions;
    Ritual ritual;
public:

    Player(std::string name, int hp, int mp, std::string deckFile);

    ~Player() = default;

    bool playCard(size_t i);

    bool playCard(size_t i, Player &enemy, size_t t);

    void drawCard();

    // place card into activeminions
    void placeCard(Card &min);

    // returns false if the player doesn't die and true if they do
    bool takeDamage(int dmg);

    Card &getActiveCard(size_t i);

    ActiveMinions &getActiveMinions();

    size_t getActiveCardSize();

    void attackPlayer(size_t i, Player &enemy);

    void attackMinion(Card &attacker, Card &enemy);

    void attackMinion(size_t i, Player &enemy, size_t j);

    size_t getHandSize();

    Hand &getHand();

    Deck &getDeck();

    Ritual &getRitual();

};

#endif
