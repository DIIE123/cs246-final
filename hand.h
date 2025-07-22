#ifndef HAND_H
#define HAND_H
#include "collection.h"

class Hand: Collection{
public:
  Hand();
  ~Hand() override;
  Hand(const Hand&) = delete;
  Hand& operator=(const Hand&) = delete;
  Hand(Hand&&) = default;
  Hand& operator=(Hand&&) = default;
  void playCard(size_t index);
};

#endif
