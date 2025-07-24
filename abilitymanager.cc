#include "abilitymanager.h"

AbilityManager::AbilityManager() {
    // Spells
    abilities["Banish"] = abilityBanish;
    abilities["Unsummon"] = abilityUnsummon;
    abilities["Recharge"] = abilityRecharge;
    abilities["Disenchant"] = abilityDisenchant;
    abilities["Raise Dead"] = abilityRaiseDead;
    abilities["Blizzard"] = abilityBlizzard;

    // Triggered Abilities
    abilities["Bone Golem"] = abilityBoneGolem;
    abilities["Fire Elemental"] = abilityFireElemental;
    abilities["Potion Seller"] = abilityPotionSeller;

    // Activated Abilities
    abilities["Novice Pyromancer"] = abilityNovicePyromancer;
    abilities["Apprentice Summoner"] = abilityApprenticeSummoner;
    abilities["Master Summoner"] = abilityMasterSummoner;

    // Rituals
    abilities["Dark Ritual"] = abilityDarkRitual;
    abilities["Aura of Power"] = abilityAuraOfPower;
    abilities["Standstill"] = abilityStandstill;
}

Ability AbilityManager::getAbility(std::string name) {
    if (abilities.count(name)) return abilities[name];
    return nullptr;
}
