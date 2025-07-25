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
      information.emplace_back(std::make_shared<MinionInfo>(it->getName(), it->getCost(), it->getAttack(), it->getDefense(), it->getAbilityDesc(), it->getAbilityCost(), 
      it->getTriggerType() == TriggerType::None));
    }
    if (it->getType() == CardType::Spell) {
      information.emplace_back(std::make_shared<SpellInfo>(it->getName(), it->getCost(), it->getAbilityDesc()));
    }
    if (it->getType() == CardType::Ritual) {
      information.emplace_back(std::make_shared<RitualInfo>(it->getName(), it->getCost(), it->getAbilityDesc(), it->getAbilityCost(), it->getDefense()));
    }
    information.emplace_back(std::make_shared<EnchantInfo>(it->getEnchantmentName(), it->getEnchantmentCost(), it->getEnchantmentDesc(), it->getAttackString(), it->getDefenseString()));
  }
  return information;
}

int Hand::getCardCost(size_t i) { 
  if (i >= cards.size() ) {
    std::cout << "In getCardCost theres an invalid index" << std::endl << std::endl;
  }
  return cards[i]->getCost(); 
}
