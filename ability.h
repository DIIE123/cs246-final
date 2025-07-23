#ifndef ABILITY_H
#define ABILITY_H

class Game;

typedef void (*Ability)(Game &game);

// Spells

// Minions
// Triggered
void abilityBoneGolem(Game &game);

// Activated
void abilityNovicePyromancer(Game &game);

// Enchantments

// Rituals

#endif
