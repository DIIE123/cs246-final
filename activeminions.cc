#include "activeminions.h"

ActiveMinions::ActiveMinions() = default;
ActiveMinions::~ActiveMinions() = default;

Card& ActiveMinions::getMinion(size_t i) {
  return *cards[i];
}

std::shared_ptr<Card> ActiveMinions::getMinionPtr(size_t i) {
  return cards[i];
}

std::vector<std::shared_ptr<CardInfo>> ActiveMinions::getInfo() {
  std::vector<std::shared_ptr<CardInfo>> information;
  for (auto& it: cards) {
    information.emplace_back(std::make_shared<MinionInfo>(it->getName(), it->getCost(), it->getAttack(), 
      it->getDefense(), it->getAbilityDesc(), it->getAbilityCost()));
  }
  return information;
}
