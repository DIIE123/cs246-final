#include "ability.h"
#include "minion.h"
#include "player.h"
#include "game.h"

// Abstract Abilities
void abilityAttackMinion(Game &game, int damage = 1) {
    game.attackMinion(game.getTargetCard(), damage);
}

// Spells
void abilityBanish(Game &game) {
    abilityAttackMinion(game, 9999);
}

void abilityUnsummon(Game &game) {}

void abilityRecharge(Game &game) {
    Card &ritual = game.getTargetCard();
    ritual.setDefense(ritual.getDefense() + 3);
}

void abilityDisenchant(Game &game) {}

void abilityRaiseDead(Game &game) {

}

void abilityBlizzard(Game &game) {
    // current player
    ActiveMinions &currentMinions = game.getActivePlayer().getActiveMinions();
    
    for (int i = 0; i < currentMinions.getSize(); ++i) {
        game.attackMinion(currentMinions.getMinion(i), 2);
    }

    // enemy player
    ActiveMinions &enemyMinions = game.getOtherPlayer().getActiveMinions();
    
    for (int i = 0; i < currentMinions.getSize(); ++i) {
        game.attackMinion(currentMinions.getMinion(i), 2);
    }
}

// Minions
// Triggered Ability
void abilityBoneGolem(Game &game) {
    Card &minion = game.getActiveCard();
    minion.setAttack(minion.getAttack() + 1);
    minion.setDefense(minion.getDefense() + 1);
}

void abilityFireElemental(Game &game) {
    abilityAttackMinion(game);
}

void abilityPotionSeller(Game &game) {
    ActiveMinions &activeMinions = game.getActivePlayer().getActiveMinions();

    for (int i = 0; i < activeMinions.getSize(); ++i) {
        Card &minion = activeMinions.getMinion(i);
        minion.setDefense(minion.getDefense() + 1);
    }
}

// Activated Ability
void abilityNovicePyromancer(Game &game) {
    abilityAttackMinion(game);
}

void abilityApprenticeSummoner(Game &game) {
    ActiveMinions &activeMinions = game.getActivePlayer().getActiveMinions();

    
}

void abilityMasterSummoner(Game &game) {
    for (int i = 0; i < 3; ++i) {
        abilityApprenticeSummoner(game);
    }
}

