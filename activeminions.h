#ifndef ACTiVE_H
#define ACTIVE_H
#include "collection.h"
#include "minion.h"
#include <memory>

class ActiveMinions: public Collection {
public:
  ActiveMinions();
  ~ActiveMinions() override;
  ActiveMinions(const ActiveMinions&) = delete;
  ActiveMinions& operator=(const ActiveMinions&) = delete;
  Card& getMinion(size_t i);

};

#endif
