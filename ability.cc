#include "ability.h"

// Ability
Ability::Ability() {}
Ability::Ability(std::string description): description{description} {}
void Ability::useAbility(Player &player, Minion &minion) {
    useChildAbility(player, minion);
}

// Minions
// Activated Ability
NovicePyromancer::NovicePyromancer(): Ability{"Deal 1 damage to target minion"} {}
void NovicePyromancer::useChildAbility(Player &player, Minion &minion) {
    minion.takeDamage(1);
}
