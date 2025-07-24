#include "deck.h"
#include "minion.h"
#include "spell.h"
#include "enchantment.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <utility>
#include <random>
#include <chrono>

Deck::Deck() = default;
Deck::~Deck() = default;

void Deck::shuffle() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng{seed};
  std::shuffle(cards.begin(), cards.end(), rng);
}

void Deck::createDeck(std::string deckfile){
  std::ifstream deck{deckfile};
  while (1) {
    std::string line;
    if (!std::getline(deck, line)) {
      break;
    }
    if (line == "Air Elemental" || line == "Earth Elemental" || line == "Fire Elemental" || line == "Bone Golem" ||
        line == "Potion Seller" || line == "Novie Pyromancer" || line == "Apprentice Summoner" || line == "Master Summoner") {
      this->addCard(std::make_unique<Minion>(line));
      continue;
    }

    if (line == "Banish" || line == "Unsommon" || line == "Recharge" || line == "Disenchant" ||
        line == "Raise Dead" || line == "Blizzard") {
      this->addCard(std::make_unique<Spell>(line));
      continue;
    }
    
    if (line == "Giant Strength") {
      this->addCard(std::make_unique<GiantStrength>(std::move(std::make_unique<Minion>("Air Elemental"))));
      continue;
    }
    if (line == "Enrage") {
      this->addCard(std::make_unique<Enrage>(std::move(std::make_unique<Minion>("Air Elemental"))));
      continue;
    }
    if (line == "Haste") {
      this->addCard(std::make_unique<Haste>(std::move(std::make_unique<Minion>("Air Elemental"))));
      continue;
    }
    if (line == "MagicFatigue") {
      this->addCard(std::make_unique<MagicFatigue>(std::move(std::make_unique<Minion>("Air Elemental"))));
      continue;
    } 
    if (line == "Silence") {
      this->addCard(std::make_unique<Silence>(std::move(std::make_unique<Minion>("Air Elemental"))));
      continue;
    }
    // this->addCard(std::make_unique<Minion>(line));
  }
}


