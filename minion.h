#ifndef MINION_H
#define MINION_H

#include <string>
#include "card.h"

class Minion: public Card {
    int attack;
    int defense;
    int maxActions = 1;
    int actions = 0;

    void readInfo(std::string name);

public:
    Minion(std::string name);
    ~Minion();
    void doDamage(Minion &m);
    // void doDamage(Player &p);
    void takeDamage(int damage);
    void decreaseActions();
    void resetActions();
    bool isDead() const;
};

#endif
