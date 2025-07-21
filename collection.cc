#include "collection.h"
#include <vector>
#include <memory>
#include <utility>


Collection::Collection() = default;

Collection::~Collection () {}

size_t Collection::getSize () {
  return cards.size();
}

void Collection::addCard(std::unique_ptr<Card> c) {
  cards.emplace_back(c);
}

std::unique_ptr<Card> Collection::removeCard(size_t index) {
  if (index >= cards.size()) {
    return nullptr;
  }
  std::unique_ptr<Card> temp = std::move(cards[index]);
  cards.erase(cards.begin() + index);
  return temp;
}
