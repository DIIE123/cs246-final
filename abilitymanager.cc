#include "abilitymanager.h"
#include "ability.h"

AbilityManager::AbilityManager() {
    // Activated Abilities
    addAbility(std::make_unique<NovicePyromancer>());
}

void AbilityManager::addAbility(std::shared_ptr<Ability> a) {
    abilities.emplace_back(std::move(a));
}

std::shared_ptr<Ability> AbilityManager::getAbility(std::string description) {
    for (auto ability : abilities) {
        if (ability->getDescription() == description) return ability;
    }

    return nullptr;
}
