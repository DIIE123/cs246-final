#include "info.h"

CardInfo::CardInfo(std::string name, size_t cost): name{name}, cost{cost} {}

MinionInfo::MinionInfo(std::string name, size_t cost, size_t damage, size_t health): 
  CardInfo{name, cost}, damage{damage}, health{health} {}
  
CardType MinionInfo::getType() {
  return CardType::Minion;
}

SpellInfo::SpellInfo(std::string name, size_t cost, std::string description):
  CardInfo{name, cost}, description{description} {}

CardType SpellInfo::getType() {
  return CardType::Spell;
}

EnchantInfo::EnchantInfo(std::string name, size_t cost, std::string modification):
  CardInfo{name, cost}, modification{modification} {}

CardType EnchantInfo::getType() {
  return CardType::Enchantment;
}

RitualInfo::RitualInfo(std::string name, size_t cost, std::string description, 
                       size_t activationCost, size_t charge):
  CardInfo{name, cost}, description{description}, activationCost{activationCost}, charge{charge} {}

CardType RitualInfo::getType() {
  return CardType::Ritual;
}
