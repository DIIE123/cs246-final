#ifndef ACTiVE_H
#define ACTIVE_H
#include "collection.h"
#include "minion.h"
#include "enchantment.h"
#include <memory>

class ActiveMinions: public Collection {
public:
  ActiveMinions();
  ~ActiveMinions() override;
  ActiveMinions(const ActiveMinions&) = delete;
  ActiveMinions& operator=(const ActiveMinions&) = delete;
  std::vector<std::shared_ptr<CardInfo>> getInfo();
  void useEnchantment(size_t i, CardType ct);
};

#endif
