#include "graveyard.h"

Graveyard::Graveyard() = default;
Graveyard::~Graveyard() = default;

std::shared_ptr<CardInfo> Graveyard::getInfo() {
  if (cards.size() == 0) {
    return nullptr;
  }
  return std::make_shared<MinionInfo>(cards.back()->getName(), cards.back()->getCost(), cards.back()->getAttack(), cards.back()->getDefense());
}
