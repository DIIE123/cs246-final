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

    Player(std::string name, int hp, int mp, std::string deckFile);

    ~Player() = default;

    bool playCard(size_t i);

    bool playCard(size_t i, Player &enemy, size_t t);

    void drawCard();

    // place card into activeminions
    void placeCard(std::shared_ptr<Card> min);

    // NEW PLAY FUNCTIONS

    void playMinion(size_t i);

    void playSpell(size_t i);

    void playSpell(size_t i, Player &enemy, size_t j);

    void playEnchant(size_t i, size_t j);

    void playRitual(size_t i);
    

    // returns false if the player doesn't die and true if they do
    bool takeDamage(int dmg);

    Card &getActiveCard(size_t i);

    std::shared_ptr<Card> getActiveCardPtr(size_t i);

    ActiveMinions &getActiveMinions();

    Graveyard &getGraveyard();

    size_t getActiveCardSize();

    void attackPlayer(size_t i, Player &enemy);

    void attackMinion(Card &attacker, Card &enemy);

    void attackMinion(size_t i, Player &enemy, size_t j);

    void killMinion(size_t i);

    bool killMinions();

    // Deal with magic
    void incrementMagic(int i);

    void setMagic(int i);

    void resetActions();

    size_t getHandSize();

    Hand &getHand();

    Deck &getDeck();

    // tranfer ownership of ritual
    std::shared_ptr<Card> getRitual();

    // Simple getters
    // health, magic, name getters
    int getHealth();

    int getMagic();

    std::string getName();

};

#endif
