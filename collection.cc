#include "collection.h"
#include <vector>
#include <memory>
#include <iostream>
#include <utility>


Collection::Collection() = default;

Collection::~Collection () {}

size_t Collection::getSize () {
  return cards.size();
}

void Collection::addCard(std::shared_ptr<Card> c) {
  cards.emplace_back(c);
}

std::shared_ptr<Card> Collection::removeCard(size_t index) {
  if (index >= cards.size()) {
    return nullptr;
  }
  std::shared_ptr<Card> temp = cards[index];
  cards.erase(cards.begin() + index);
  return temp;
}

Card& Collection::getCard(size_t i) {
  return *cards[i];
}

std::shared_ptr<Card> Collection::getCardPtr(size_t i) {
  return cards[i];
}
