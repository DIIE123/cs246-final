#include "collection.h"

class Hand: Collection{
public:
  Hand();
  ~Hand() override;
  Hand(const Hand&) = delete;
  Hand& operator=(const Hand&) = delete;
  Hand(Hand&&);
  Hand& operator=(Hand&&);
  void playCard(size_t index);
};