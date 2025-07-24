#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include <memory>
#include "minion.h"
#include "type.h"

class Enchantment: public Minion {
    std::string enchantmentName;
    std::string attackString;
    std::string defenseString;
    std::string abilityDesc;

    virtual CardType getType() override;

protected:
    std::unique_ptr<Minion> minion = nullptr;

public:
    Enchantment(std::string enchantmentName, size_t cost, std::string attackString, std::string defenseString, std::unique_ptr<Minion> minion);
    Enchantment(std::string enchantmentName, size_t cost, std::string abilityDesc, std::unique_ptr<Minion> minion);
    virtual ~Enchantment() = 0;
    virtual std::string getAttackString();
    virtual std::string getDefenseString();
    virtual std::string getAbilityDesc();
};

class GiantStrength: public Enchantment {
public:
    GiantStrength(std::unique_ptr<Minion> minion);
    ~GiantStrength();
    size_t getAttack();
    size_t getDefense();
    virtual CardType getType() override;
};

class Enrage: public Enchantment {
public:
    Enrage(std::unique_ptr<Minion> minion);
    ~Enrage();
    size_t getAttack() override;
    size_t getDefense() override;
    virtual CardType getType() override;
};

class Haste: public Enchantment {
public:
    Haste(std::unique_ptr<Minion> minion);
    ~Haste();
    size_t getMaxActions() override;
    virtual CardType getType() override;
};

class MagicFatigue: public Enchantment {
public:
    MagicFatigue(std::unique_ptr<Minion> minion);
    ~MagicFatigue();
    size_t getAbilityCost() override;
    virtual CardType getType() override;
};

class Silence: public Enchantment {
public:
    Silence(std::unique_ptr<Minion> minion);
    ~Silence();
    virtual CardType getType() override;
    bool getHasAbility();
};

#endif
