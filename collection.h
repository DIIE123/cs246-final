#ifndef COLLECTION_H
#define COLLECTION_H
#include "card.h"
#include <vector>
#include <memory>

class Collection {
protected: 
  std::vector<std::shared_ptr<Card>> cards;

public:
  Collection();
  virtual ~Collection() = 0;
  Collection(const Collection&) = delete;
  Collection &operator=(const Collection&) = delete;
  size_t getSize();
  virtual void addCard(std::shared_ptr<Card> c);
  std::shared_ptr<Card> removeCard(size_t index);
};

#endif

