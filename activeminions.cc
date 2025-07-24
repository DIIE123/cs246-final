#include "activeminions.h"

ActiveMinions::ActiveMinions() = default;
ActiveMinions::~ActiveMinions() = default;

Card& ActiveMinions::getMinion(size_t i) {
  return *cards[i];
}

std::vector<std::unique_ptr<CardInfo>> ActiveMinions::getInfo() {
  std::vector<std::unique_ptr<CardInfo>> information;
  for (auto& it: cards) {
    information.emplace_back(std::make_unique<MinionInfo>(it->getName(), it->getCost(), it->getAttack(), it->getDefense()));
  }
  return information;
}
