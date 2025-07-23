#include "activeminions.h"

ActiveMinions::ActiveMinions() = default;
ActiveMinions::~ActiveMinions() = default;

Card& ActiveMinions::getMinion(size_t i) {
  return *cards[i];
}