#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H

#include <string>
#include "ability.h"
#include <vector>
#include <memory>

class AbilityManager {
protected: 
    std::vector<std::shared_ptr<Ability>> abilities;
    void addAbility(std::shared_ptr<Ability> a);

public:
    AbilityManager();
    std::shared_ptr<Ability> getAbility(std::string description);
};

#endif
