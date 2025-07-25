#ifndef HAND_H
#define HAND_H
#include "collection.h"
#include "info.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

class Hand: public Collection{
public:
  Hand();
  ~Hand() override;
  Hand(const Hand&) = delete;
  Hand& operator=(const Hand&) = delete;
  Hand(Hand&&) = default;
  Hand& operator=(Hand&&) = default;
  void playCard(size_t index);
  std::vector<std::shared_ptr<CardInfo>> getInfo();
  int getCardCost(size_t i);
};

#endif
