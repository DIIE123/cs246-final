#include "graveyard.h"

Graveyard::Graveyard() = default;
Graveyard::~Graveyard() = default;

std::shared_ptr<CardInfo> Graveyard::getInfo() {
  if (cards.size() == 0) {
    return nullptr;
  }
  return std::make_shared<MinionInfo>(cards.back()->getName(), cards.back()->getCost(), 
    cards.back()->getAttack(), cards.back()->getDefense(), cards.back()->getAbilityDesc(), cards.back()->getAbilityCost(), cards.back()->getTriggerType() == TriggerType::None);
}

Card &Graveyard::getTopCard() {
  return *cards.back();
}

std::shared_ptr<Card> Graveyard::removeTopCard() {
  if (cards.size() <= 0) return nullptr;

  std::shared_ptr<Card> temp = cards.back();
  cards.pop_back();
  return temp;
}

