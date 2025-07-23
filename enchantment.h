#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include "minion.h"

class Enchantment: public Minion {
    std::string attackString = "";
    std::string defenseString = "";
    std::string abilityDesc = "";

    void readInfo(std::string name) override;

protected:
    Minion *minion = nullptr;

public:
    Enchantment(std::string name, size_t cost, std::string attackString, std::string defenseString, Minion* minion);
    Enchantment(std::string name, size_t cost, std::string abilityDesc, Minion* minion);
    virtual ~Enchantment() = 0;
    std::string getAttackString();
    std::string getDefenseString();
    std::string getAbilityDesc();
};

class GiantStrength: public Enchantment {
public:
    GiantStrength(Minion* minion);
    ~GiantStrength();
    size_t getAttack();
    size_t getDefense();
};

class Enrage: public Enchantment {
public:
    Enrage(Minion* minion);
    ~Enrage();
    size_t getAttack();
    size_t getDefense();
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
