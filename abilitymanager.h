#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include "ability.h"

class AbilityManager {
    std::vector<std::shared_ptr<Ability>> abilities;
    void addAbility(std::shared_ptr<Ability> a);

public:
    AbilityManager();
    std::shared_ptr<Ability> getAbility(std::string description);
};

#endif
