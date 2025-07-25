#include "hand.h"
#include <memory>

Hand::Hand() = default;
Hand::~Hand() = default;

void Hand::playCard(size_t index) {
  if (index < cards.size()) {
    // cards[index]->play();
  }
}

std::vector<std::shared_ptr<CardInfo>> Hand::getInfo() {
  std::vector<std::shared_ptr<CardInfo>> information;
  for (auto& it: cards) {
    if(it->getType() == CardType::Minion) {
      information.emplace_back(std::make_shared<MinionInfo>(it->getName(), it->getCost(), it->getAttack(), it->getDefense(), it->getAbilityDesc(), it->getAbilityCost()));
    }
    if (it->getType() == CardType::Spell) {
      information.emplace_back(std::make_shared<SpellInfo>(it->getName(), it->getCost(), it->getAbilityDesc()));
    }
  }
  return information;
}
