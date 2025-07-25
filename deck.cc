#include "deck.h"
#include "minion.h"
#include "spell.h"
#include "ritual.h"
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

void Deck::createDeck(std::string deckfile, Player &player){
  std::ifstream deck{deckfile};
  while (1) {
    std::string line;
    if (!std::getline(deck, line)) {
      break;
    }
    if (line == "Air Elemental" || line == "Earth Elemental" || line == "Fire Elemental" || line == "Bone Golem" ||
        line == "Potion Seller" || line == "Novice Pyromancer" || line == "Apprentice Summoner" || line == "Master Summoner") {
      this->addCard(std::make_shared<Minion>(line, player));
      continue;
    }

    if (line == "Banish" || line == "Unsummon" || line == "Recharge" || line == "Disenchant" ||
        line == "Raise Dead" || line == "Blizzard") {
      this->addCard(std::make_shared<Spell>(line, player));
      continue;
    }

    // if (line == "Dark Ritual" || line == "Aura of Power" || line == "Standstill") {
    //   this->addCard(std::make_shared<Ritual>(line, player));
    //   continue;
    // }
    
    /*
    if (line == "Giant Strength") {
      this->addCard(std::make_shared<GiantStrength>(std::make_shared<Minion>("Air Elemental", player), player));
      continue;
    }
    if (line == "Enrage") {
      this->addCard(std::make_shared<Enrage>(std::make_shared<Minion>("Air Elemental", player), player));
      continue;
    }
    if (line == "Haste") {
      this->addCard(std::make_shared<Haste>(std::make_shared<Minion>("Air Elemental", player), player));
      continue;
    }
    if (line == "MagicFatigue") {
      this->addCard(std::make_shared<MagicFatigue>(std::make_shared<Minion>("Air Elemental", player), player));
      continue;
    } 
    if (line == "Silence") {
      this->addCard(std::make_shared<Silence>(std::make_shared<Minion>("Air Elemental", player), player));
      continue;
    }
      */
    // this->addCard(std::make_shared<Minion>(line, player));
  }
}


