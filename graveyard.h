
#ifndef GRAVE_H
#define GRAVE_H
#include "collection.h"

class Graveyard: public Collection {
public:
  Graveyard();
  ~Graveyard() override;
  Graveyard(const Graveyard&) = delete;
  Graveyard& operator=(const Graveyard&) = delete;
  std::unique_ptr<CardInfo> getInfo();
};

#endif
