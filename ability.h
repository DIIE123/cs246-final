#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include "minion.h"

class Minion;
class Player;

class Ability {
    std::string description;

    virtual void useChildAbility(Player *player, Minion *minion) = 0;
    
public:
    Ability();
    Ability(std::string description);
    void useAbility(Player *player, Minion *minion);
    std::string getDescription();
};

// Spells

// Minions
// Triggered

// Activated
class NovicePyromancer: public Ability {
    void useChildAbility(Player *player, Minion *minion) override;
    
public:
    NovicePyromancer();
};
// Enchantments

// Rituals

#endif
