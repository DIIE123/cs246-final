#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include "collection.h"
#include "deck.h"
#include "hand.h"
#include "graveyard.h"
#include "card.h"
#include "minion.h"
#include "activeminions.h"
#include "type.h"
#include "ritual.h"

class Player {
    std::string name;
    int health;
    int magic;
    Deck deck;
    Hand hand;
    ActiveMinions activeMinions;
    Graveyard graveyard;
    std::shared_ptr<Card> ritual;
public:

    Player(std::string name, int hp, int mp, std::string deckFile, bool isTesting);

    ~Player() = default;

    void drawCard();

    // place card into activeminions
    void placeCard(std::shared_ptr<Card> min);

    // returns false if the player doesn't die and true if they do
    bool takeDamage(int dmg);

    Card &getActiveCard(size_t i);

    Card &getHandCard(size_t i);

    std::shared_ptr<Card> getActiveCardPtr(size_t i);

    std::shared_ptr<Card> getHandCardPtr(size_t i);

    ActiveMinions &getActiveMinions();

    Graveyard &getGraveyard();

    size_t getActiveCardSize();

    void attackPlayer(size_t i, Player &enemy);

    void attackMinion(Card &attacker, Card &enemy);

    void attackMinion(size_t i, Player &enemy, size_t j);

    bool killMinions();

    // Deal with magic
    void incrementMagic(int i);

    void setMagic(int i);

    void resetActions();

    size_t getHandSize();

    Hand &getHand();

    Deck &getDeck();

    // share ownership of ritual
    std::shared_ptr<Card> getRitual();

    void setRitual(std::shared_ptr<Card> card);

    // Simple getters
    // health, magic, name getters
    int getHealth();

    int getMagic();

    std::string getName();

    bool isDead();

    // operator override
    bool operator!=(const Player &other) const; 
};

#endif
