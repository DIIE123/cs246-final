#include "enchantment.h"

// Enchantment
Enchantment::Enchantment(std::string enchantmentName, int cost, std::string attackString, std::string defenseString, std::unique_ptr<Minion> minion):
    Minion{minion->getName()}, enchantmentName{enchantmentName}, attackString{attackString}, defenseString{defenseString}, minion{std::move(minion)} {}

Enchantment::Enchantment(std::string enchantmentName, int cost, std::string abilityDesc, std::unique_ptr<Minion> minion):
    Minion{minion->getName()}, enchantmentName{enchantmentName}, abilityDesc{abilityDesc}, minion{std::move(minion)} {}


CardType Enchantment::getType() {
  return CardType::Enchantment;
}

Enchantment::~Enchantment() {}


std::string Enchantment::getAttackString() { return attackString; }
std::string Enchantment::getDefenseString() { return defenseString; }
std::string Enchantment::getAbilityDesc() { return abilityDesc; }

// Giant Strength
GiantStrength::GiantStrength(std::unique_ptr<Minion> minion): Enchantment{"Giant Strength", 1, "+2", "+2", std::move(minion)} {}
GiantStrength::~GiantStrength() = default;
int GiantStrength::getAttack() { return minion->getAttack() + 2; }
int GiantStrength::getDefense() { return minion->getDefense() + 2; }
CardType GiantStrength::getType() { return CardType::GiantStrength; } 

// Enrage
Enrage::Enrage(std::unique_ptr<Minion> minion): Enchantment{"Enrage", 2, "*2", "*2", std::move(minion)} {}
Enrage::~Enrage() = default;
int Enrage::getAttack() { return minion->getAttack() * 2; }
int Enrage::getDefense() { return minion->getDefense() * 2; }
CardType Enrage::getType() { return CardType::Enrage; }

// Haste
Haste::Haste(std::unique_ptr<Minion> minion): Enchantment{"Haste", 1, "Enchanted minion gains +1 action each turn", std::move(minion)} {}
Haste::~Haste() = default;
int Haste::getMaxActions() { return minion->getMaxActions() + 1; }
CardType Haste::getType() { return CardType::Haste; }
// TODO: Make haste give minion + 1 action when placed

// Magic Fatigue
MagicFatigue::MagicFatigue(std::unique_ptr<Minion> minion): Enchantment{"Magic Fatigue", 0, "Enchanted minion's activated ability costs 2 more", std::move(minion)} {}
MagicFatigue::~MagicFatigue() = default;
int MagicFatigue::getAbilityCost() { return minion->getAbilityCost() + 2; }
CardType MagicFatigue::getType() { return CardType::MagicFatigue; }

// Silence
Silence::Silence(std::unique_ptr<Minion> minion): Enchantment{"Silence", 1, "Enchanted minion cannot use abilities", std::move(minion)} {}
Silence::~Silence() = default;
bool Silence::getHasAbility() { return false; }
CardType Silence::getType() { return CardType::Silence; }
