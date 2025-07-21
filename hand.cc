#include "hand.h"

Hand::Hand() = default;
Hand::~Hand() = default;

Hand::Hand(Hand&&) = default;
Hand& Hand::operator=(Hand&&) = default;

void Hand::playCard(size_t index) {
  if (index < cards.size()) {
    // cards[index]->play();
  }
}
