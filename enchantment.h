#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include <memory>
#include <algorithm>
#include "minion.h"
#include "type.h"

class Enchantment: public Minion {
    std::string enchantmentName;
    int enchantmentCost;
    std::string attackString;
    std::string defenseString;
    std::string enchantmentDesc;

    virtual CardType getType() override;

protected:
    std::shared_ptr<Card> minion = nullptr;

public:
    Enchantment(std::string enchantmentName, int cost, std::string attackString, std::string defenseString, std::shared_ptr<Card> minion);
    Enchantment(std::string enchantmentName, int cost, std::string enchantmentDesc, std::shared_ptr<Card> minion);
    virtual ~Enchantment() = 0;
    int getEnchantmentCost() override;
    std::string getAttackString() override;
    std::string getDefenseString() override;
    std::string getEnchantmentName() override;
    std::string getEnchantmentDesc() override;
    std::shared_ptr<Card> getPointer() override;
    
};

class GiantStrength: public Enchantment {
public:
    GiantStrength(std::shared_ptr<Card> minion);
    ~GiantStrength();
    int getAttack();
    int getDefense();
    virtual CardType getType() override;
};

class Enrage: public Enchantment {
public:
    Enrage(std::shared_ptr<Card> minion);
    ~Enrage();
    int getAttack() override;
    int getDefense() override;
    virtual CardType getType() override;
};

class Haste: public Enchantment {
public:
    Haste(std::shared_ptr<Card> minion);
    ~Haste();
    int getMaxActions() override;
    virtual CardType getType() override;
};

class MagicFatigue: public Enchantment {
public:
    MagicFatigue(std::shared_ptr<Card> minion);
    ~MagicFatigue();
    int getAbilityCost() override;
    virtual CardType getType() override;
};

class Silence: public Enchantment {
public:
    Silence(std::shared_ptr<Card> minion);
    ~Silence();
    virtual CardType getType() override;
    bool getHasAbility();
};

#endif
