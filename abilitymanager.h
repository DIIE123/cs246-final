#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H

#include <string>
#include <map>
#include "ability.h"

class AbilityManager {
    std::map<std::string, Ability> abilities;

public:
    AbilityManager();
    Ability getAbility(std::string name);
    
};

#endif
