#include "info.h"

CardInfo::CardInfo(std::string name, size_t cost, size_t damage, size_t health): 
  name{name}, cost{cost}, damage{damage}, health{health} {}

CardInfo::CardInfo(std::string name, size_t cost, std::string description): 
  name{name}, cost{cost}, description{description} {}

CardInfo::CardInfo(std::string name, size_t cost, std::string description, std::string modification):
  name{name}, cost{cost}, description{description}, modification{modification} {}

CardInfo::CardInfo(std::string name, size_t cost, std::string description, size_t activationCost, size_t charge):
  name{name}, cost{cost}, description{description}, activationCost{activationCost}, charge{charge} {}

MinionInfo::MinionInfo(std::string name, size_t cost, size_t damage, size_t health): 
  CardInfo{name, cost, damage, health} {}
  
CardType MinionInfo::getType() {
  return CardType::Minion;
}

SpellInfo::SpellInfo(std::string name, size_t cost, std::string description):
  CardInfo{name, cost, description} {}

CardType SpellInfo::getType() {
  return CardType::Spell;
}

EnchantInfo::EnchantInfo(std::string name, size_t cost, std::string description, std::string modification):
  CardInfo{name, cost, description, modification} {}

CardType EnchantInfo::getType() {
  return CardType::Enchantment;
}

RitualInfo::RitualInfo(std::string name, size_t cost, std::string description, 
                       size_t activationCost, size_t charge):
  CardInfo{name, cost, description, activationCost, charge} {}

CardType RitualInfo::getType() {
  return CardType::Ritual;
}
