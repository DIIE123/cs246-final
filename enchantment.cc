#include "enchantment.h"

// Enchantment
Enchantment::Enchantment(std::string name, size_t cost, std::string attackString, std::string defenseString, Minion* minion):
    Minion{name, cost}, attackString{attackString}, defenseString{defenseString} {}

Enchantment::Enchantment(std::string name, size_t cost, std::string abilityDesc, Minion* minion):
    Minion{name, cost}, abilityDesc{abilityDesc}, minion{minion} {}

Enchantment::~Enchantment() {delete minion;};


std::string Enchantment::getAttackString() { return attackString; }
std::string Enchantment::getDefenseString() { return defenseString; }
std::string Enchantment::getAbilityDesc() { return abilityDesc; }

// Giant Strength
GiantStrength::GiantStrength(Minion* minion): Enchantment{"Giant Strength", 1, "+2", "+2", minion} {}
size_t GiantStrength::getAttack() { return minion->getAttack() + 2; }
size_t GiantStrength::getDefense() { return minion->getDefense() + 2; }

// Enrage
Enrage::Enrage(Minion* minion): Enchantment{"Enrage", 2, "*2", "*2", minion} {}
size_t Enrage::getAttack() { return minion->getAttack() * 2; }
size_t Enrage::getDefense() { return minion->getDefense() * 2; }

// Haste
Haste::Haste(): Enchantment{"Haste", 1, "Enchanted minion gains +1 action each turn"} {}
int Haste::getMaxActions() { return minion->getMaxActions() + 1; }
// TODO: Make haste give minion + 1 action when placed

// Magic Fatigue
MagicFatigue::MagicFatigue(): Enchantment{"Magic Fatigue", 0, "Enchanted minion's activated ability costs 2 more"} {}
int MagicFatigue::getAbilityCost() { return minion->getAbilityCost() + 2; }

// Silence
Silence::Silence(): Enchantment{"Silence", 1, "Enchanted minion cannot use abilities"} {}
bool Silence::getHasAbility() { return false; }
