#include "abilitymanager.h"

AbilityManager::AbilityManager() {
    // // Activated Abilities
    // abilities["Bone Golem"] = abilityBoneGolem;

    // // Triggered Abilities
    // abilities["Novice Pyromancer"] = abilityNovicePyromancer;
}

Ability AbilityManager::getAbility(std::string name) {
    if (abilities.count(name)) return abilities[name];
    return nullptr;
}
