#ifndef ABILITY_H
#define ABILITY_H

class Game;

typedef void (*Ability)(Game &game);

// Spells
void abilityBanish(Game &game);
void abilityUnsummon(Game &game);
void abilityRecharge(Game &game);
void abilityDisenchant(Game &game);
void abilityRaiseDead(Game &game);
void abilityBlizzard(Game &game);

// Minions
// Triggered
void abilityBoneGolem(Game &game);
void abilityFireElemental(Game &game);
void abilityPotionSeller(Game &game);

// Activated
void abilityNovicePyromancer(Game &game);
void abilityApprenticeSummoner(Game &game);
void abilityMasterSummoner(Game &game);

// Enchantments

// Rituals
void abilityDarkRitual(Game &game);
void abilityAuraOfPower(Game &game);
void abilityStandstill(Game &game);

#endif
