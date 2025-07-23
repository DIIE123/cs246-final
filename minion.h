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
    TriggerType readTriggerType(std::string input);

public:
    Minion(std::string name);
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

    // Setters
    void setAttack(int attack);
    void setDefense(int defense);
    void setActions(int actions);
    void setMaxActions(int maxActions);
    void setAbilityCost(int abilityCost);
};

#endif
