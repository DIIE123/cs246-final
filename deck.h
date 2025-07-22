#ifndef DECK_H
#define DECK_H
#include "collection.cc"
#include <string>

class Deck: public Collection{
public:
  Deck();
  ~Deck() override;
  Deck(const Deck&) = delete;
  Deck& operator=(const Deck&) = delete;
  Deck(Deck&&);
  Deck& operator=(Deck&&);
  void shuffle();
  void createDeck(std::string deckfile);
};



#endif
