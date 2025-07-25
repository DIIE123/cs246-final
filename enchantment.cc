#include "enchantment.h"

// Enchantment
Enchantment::Enchantment(std::string enchantmentName, int cost, std::string attackString, std::string defenseString, std::shared_ptr<Card> minion):
    Minion{minion->getName()}, enchantmentName{enchantmentName}, enchantmentCost{cost}, attackString{attackString}, 
      defenseString{defenseString}, enchantmentDesc{enchantmentDesc}, minion{minion} {}

Enchantment::Enchantment(std::string enchantmentName, int cost, std::string enchantmentDesc, std::shared_ptr<Card> minion):
    Minion{minion->getName()}, enchantmentName{enchantmentName}, enchantmentCost{cost}, enchantmentDesc{enchantmentDesc}, minion{minion} {}


CardType Enchantment::getType() {
  return CardType::Enchantment;
}

std::shared_ptr<Card> Enchantment::getPointer() {
  return minion;
}

Enchantment::~Enchantment() {}

std::string Enchantment::getEnchantmentName() { return enchantmentName; }
int Enchantment::getEnchantmentCost() { return enchantmentCost; }
std::string Enchantment::getAttackString() { return attackString; }
std::string Enchantment::getDefenseString() { return defenseString; }
std::string Enchantment::getEnchantmentDesc() { return enchantmentDesc; }

// Giant Strength
GiantStrength::GiantStrength(std::shared_ptr<Card> minion): Enchantment{"Giant Strength", 1, "+2", "+2", minion} {}
GiantStrength::~GiantStrength() = default;
int GiantStrength::getAttack() { return minion->getAttack() + 2; }
int GiantStrength::getDefense() { return minion->getDefense() + 2; }
CardType GiantStrength::getType() { return CardType::GiantStrength; } 

// Enrage
Enrage::Enrage(std::shared_ptr<Card> minion): Enchantment{"Enrage", 2, "*2", "*2", minion} {}
Enrage::~Enrage() = default;
int Enrage::getAttack() { return minion->getAttack() * 2; }
int Enrage::getDefense() { return minion->getDefense() * 2; }
CardType Enrage::getType() { return CardType::Enrage; }

// Haste
Haste::Haste(std::shared_ptr<Card> minion): Enchantment{"Haste", 1, "Enchanted minion gains +1 action each turn.", minion} {}
Haste::~Haste() = default;
int Haste::getMaxActions() { return minion->getMaxActions() + 1; }
CardType Haste::getType() { return CardType::Haste; }
// TODO: Make haste give minion + 1 action when placed

// Magic Fatigue
MagicFatigue::MagicFatigue(std::shared_ptr<Card> minion): Enchantment{"Magic Fatigue", 0, "Enchanted minion's activated ability costs 2 more.", minion} {}
MagicFatigue::~MagicFatigue() = default;
int MagicFatigue::getAbilityCost() { return minion->getAbilityCost() + 2; }
CardType MagicFatigue::getType() { return CardType::MagicFatigue; }

// Silence
Silence::Silence(std::shared_ptr<Card> minion): Enchantment{"Silence", 1, "Enchanted minion cannot use abilities.", minion} {}
Silence::~Silence() = default;
bool Silence::getHasAbility() { return false; }
CardType Silence::getType() { return CardType::Silence; }
