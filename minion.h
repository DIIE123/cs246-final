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

    void readInfo(std::string name) override;

public:
    Minion(std::string name);
    Minion(std::string name, size_t cost);
    CardType getType() override;
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

    // Setters
    void setAttack(int attack);
    void setDefense(int defense);
    void setMaxActions(int maxActions);
    void setActions(int actions);
    void setAbilityCost(int abilityCost);
};

#endif
