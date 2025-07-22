#include "deck.h"
#include "minion.h"
#include <fstream>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>

Deck::Deck() = default;
Deck::~Deck() = default;

Deck::Deck(Deck&&) = default;
Deck& Deck::operator=(Deck&&) = default;

void Deck::shuffle() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng{seed};
  std::shuffle(cards.begin(), cards.end(), rng);
}

void Deck::createDeck(std::string deckfile){
  std::ifstream deck{deckfile};
  while (1) {
    std::string line;
    if (!(deck >> line)) {
      break;
    }
    this->addCard(std::make_unique<Minion>(line));
  }
}


