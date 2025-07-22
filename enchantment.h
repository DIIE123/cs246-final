#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include "minion.h"

class Enchantment: public Minion {
    std::string attackString = "";
    std::string defenseString = "";
    std::string abilityDesc = "";

protected:
    Minion *minion = nullptr;

public:
    Enchantment(std::string name, int cost, std::string attackString, std::string defenseString);
    Enchantment(std::string name, int cost, std::string abilityDesc);
    void setMinion(Minion *minion);
    Minion* getMinion();
    std::string getAttackString();
    std::string getDefenseString();
    std::string getAbilityDesc();
};

class GiantStrength: public Enchantment {
public:
    GiantStrength();
    int getAttack() override;
    int getDefense() override;
};

class Enrage: public Enchantment {
public:
    Enrage();
    int getAttack() override;
    int getDefense() override;
};

class Haste: public Enchantment {
public:
    Haste();
    int getMaxActions() override;
};

class MagicFatigue: public Enchantment {
public:
    MagicFatigue();
    int getAbilityCost() override;
};

class Silence: public Enchantment {
public:
    Silence();
    bool getHasAbility() override;
};

#endif
