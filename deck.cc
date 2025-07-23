#include "deck.h"
#include "minion.h"
#include "spell.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
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
    if (line == "Air Elemental") {
      this->addCard(std::make_unique<Minion>(line));
      continue;
    }
    if (line == "Banish") {
      this->addCard(std::make_unique<Spell>(line));
      continue;
    }
    // this->addCard(std::make_unique<Minion>(line));
  }
}


