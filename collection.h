#ifndef COLLECTION_H
#define COLLECTION_H
#include "card.h"
#include <vector>
#include <memory>

class Collection {
protected: 
  std::vector<std::unique_ptr<Card>> cards;

public:
  Collection();
  virtual ~Collection() = 0;
  Collection(const Collection&) = delete;
  Collection &operator=(const Collection&) = delete;
  size_t getSize();
  virtual void addCard(std::unique_ptr<Card> c);
  std::unique_ptr<Card> removeCard(size_t index);
};

#endif

