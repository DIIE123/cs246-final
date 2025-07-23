#ifndef CARD_H
#define CARD_H
#include <string>
#include <memory>
#include "type.h"
#include "ability.h"
#include "abilitymanager.h"

class Game;

class Card {
protected:
    static std::unique_ptr<AbilityManager> am;

    std::string name;
    int cost;
    std::string abilityDesc = "";
    Ability abilityFunc = nullptr;
    
    virtual void readInfo(std::string name) = 0;

public:
    Card();
    Card(std::string name, size_t cost);
    virtual ~Card();
    void useAbility(Game &game);

    std::string getName();
    size_t getCost();
    std::string getAbilityDesc();
    virtual CardType getType() = 0;
};

#endif
