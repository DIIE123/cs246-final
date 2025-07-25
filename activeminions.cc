#include "activeminions.h"

ActiveMinions::ActiveMinions() = default;
ActiveMinions::~ActiveMinions() = default;

std::vector<std::shared_ptr<CardInfo>> ActiveMinions::getInfo() {
  std::vector<std::shared_ptr<CardInfo>> information;
  for (auto& it: cards) {
    information.emplace_back(std::make_shared<MinionInfo>(it->getName(), it->getCost(), it->getAttack(), 
      it->getDefense(), it->getAbilityDesc(), it->getAbilityCost(), it->getTriggerType() == TriggerType::Active));
  }
  return information;
}

void ActiveMinions::useEnchantment(size_t i, CardType ct, Player& p) {
  if (i >= cards.size()) {
    return;
  }
  if (ct == CardType::GiantStrength) {
    cards[i] = std::make_shared<GiantStrength>(cards[i], p);
    return;
  }
  if (ct == CardType::Enrage) {
    cards[i] = std::make_shared<Enrage>(cards[i], p);
    return;
  }
  if (ct == CardType::Haste) {
    cards[i] = std::make_shared<Haste>(cards[i], p);
    return;
  }
  if (ct == CardType::MagicFatigue) {
    cards[i] = std::make_shared<MagicFatigue>(cards[i], p);
    return;
  }
  if (ct == CardType::Silence) {
    cards[i] = std::make_shared<Silence>(cards[i], p);
    return;
  } 
}

void ActiveMinions::removeEnchantment(size_t i) {
  if (cards[i]->getType() == CardType::Minion) {
    return;
  }
  cards[i] = cards[i]->getPointer();
}


