#include "hand.h"
#include <memory>

Hand::Hand() = default;
Hand::~Hand() = default;

void Hand::playCard(size_t index) {
  if (index < cards.size()) {
    // cards[index]->play();
  }
}

std::vector<std::unique_ptr<CardInfo>> Hand::getInfo() {
  std::vector<std::unique_ptr<CardInfo>> information;
  for (auto& it: cards) {
    if(it->getType() == CardType::Minion) {
      information.emplace_back(std::make_unique<MinionInfo>(it->getName(), it->getCost(), it->getAttack(), it->getDefense()));
      continue;
    }
    if (it->getType() == CardType::Spell) {
      information.emplace_back(std::make_unique<SpellInfo>(it->getName(), it->getCost(), it->getAbilityDesc()));
    }
  }
  return information;
}
