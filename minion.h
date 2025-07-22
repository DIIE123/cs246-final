#ifndef MINION_H
#define MINION_H

#include <string>
#include "card.h"

enum TriggerType {
    NONE,
    START,
    END,
    ENTER,
    LEAVE
};

class Minion: public Card {
    int attack;
    int defense;
    int maxActions = 1;
    int actions = 0;
    int abilityCost = 0;
    TriggerType triggerType = NONE;

    void readInfo(std::string name) override;

public:
    Minion(std::string name);
    void doDamage(Minion &other);
    // void doDamage(Player &p);
    void takeDamage(int damage);
    void decreaseActions();
    void resetActions();
    bool isDead() const;

    int getActions();

    virtual int getAttack();
    virtual int getDefense();
    virtual int getMaxActions();
    virtual int getAbilityCost();
};

#endif
