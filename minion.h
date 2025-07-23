#ifndef MINION_H
#define MINION_H

#include <string>
#include "card.h"

class Minion: public Card {
    friend class Enchantment;

    int attack;
    int defense;
    int maxActions = 1;
    int actions = 0;
    int abilityCost = 0;
    std::string triggerType = "";

    Player &owner;
    Player &opponent;

    void readInfo(std::string name) override;

public:
    Minion(std::string name, Player &owner, Player &opponent);
    void doDamage(Minion &other);
    void doDamage(Player &p);
    void takeDamage(int damage);
    void decreaseActions();
    void resetActions();
    bool isDead() const;

    // Getters
    int getAttack();
    int getDefense();
    int getMaxActions();
    int getActions();
    int getAbilityCost();
    std::string getType() override;
};

#endif
