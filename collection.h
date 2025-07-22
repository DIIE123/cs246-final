#ifndef COLLECTION_H
#define COLLECTION_H
#include <vector>
#include <memory>

class Card;

class Collection {
protected: 
  std::vector<std::unique_ptr<Card>> cards;

public:
  Collection();
  virtual ~Collection() = 0;
  size_t getSize();
  virtual void addCard(std::unique_ptr<Card> c);
  virtual std::unique_ptr<Card> removeCard(size_t index);
};

#endif

