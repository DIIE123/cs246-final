#ifndef ABILITY_H
#define ABILITY_H

class Game;

typedef bool (*Ability)(Game &game);

// Spells
bool abilityBanish(Game &game);
bool abilityUnsummon(Game &game);
bool abilityRecharge(Game &game);
bool abilityDisenchant(Game &game);
bool abilityRaiseDead(Game &game);
bool abilityBlizzard(Game &game);

// Minions
// Triggered
bool abilityBoneGolem(Game &game);
bool abilityFireElemental(Game &game);
bool abilityPotionSeller(Game &game);

// Activated
bool abilityNovicePyromancer(Game &game);
bool abilityApprenticeSummoner(Game &game);
bool abilityMasterSummoner(Game &game);

// Rituals
bool abilityDarkRitual(Game &game);
bool abilityAuraOfPower(Game &game);
bool abilityStandstill(Game &game);

#endif
