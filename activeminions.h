#include "collection.h"
#include "minion.h"
#include <memory>

class ActiveMinions: public Collection {
  ActiveMinions();
  ~ActiveMinions() override;
  ActiveMinions(const ActiveMinions&) = delete;
  ActiveMinions& operator=(const ActiveMinions&) = delete;
};