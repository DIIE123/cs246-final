#ifndef CARD_H
#define CARD_H
#include <string>
#include <memory>
#include "type.h"
#include "ability.h"
#include "abilitymanager.h"

class Card {
protected:
    static std::unique_ptr<AbilityManager> am;

    std::string name;
    size_t cost;
    virtual void readInfo(std::string name) = 0;

public:
    Card();
    Card(std::string name, size_t cost);
    virtual ~Card();
    void useAbility(Player *player = nullptr, Minion *minion = nullptr);
    virtual CardType getType() = 0;

    std::string getName();
    size_t getCost();
};

#endif
