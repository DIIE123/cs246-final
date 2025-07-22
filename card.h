#ifndef CARD_H
#define CARD_H
#include <string>
#include <memory>
#include "ability.h"

class Card {
protected:
    std::string name;
    int cost;
    std::shared_ptr<Ability> ability;
    virtual void readInfo(std::string name) = 0;

public:
    Card();
    virtual ~Card();
    void useAbility(Player *player = nullptr, Minion *minion = nullptr);

    std::string getName();
    int getCost();
};

#endif
