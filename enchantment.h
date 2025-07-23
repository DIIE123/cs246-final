#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include "minion.h"

class Enchantment: public Card {
    std::string attackString = "";
    std::string defenseString = "";
    std::string abilityDesc = "";

    void readInfo(std::string name) override;

protected:
    Minion *minion = nullptr;

public:
    Enchantment(std::string name, int cost, std::string attackString, std::string defenseString);
    Enchantment(std::string name, int cost, std::string abilityDesc);
    virtual ~Enchantment() = 0;
    void setMinion(Minion *minion);
    Minion* getMinion();
    std::string getAttackString();
    std::string getDefenseString();
    std::string getAbilityDesc();
};

class GiantStrength: public Enchantment {
public:
    GiantStrength();
    ~GiantStrength();
};

class Enrage: public Enchantment {
public:
    Enrage();
    ~Enrage();
};

class Haste: public Enchantment {
public:
    Haste();
    ~Haste();
};

class MagicFatigue: public Enchantment {
public:
    MagicFatigue();
    ~MagicFatigue();
};

class Silence: public Enchantment {
public:
    Silence();
    ~Silence();
};

#endif
