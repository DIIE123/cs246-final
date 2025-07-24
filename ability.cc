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

void abilityUnsummon(Game &game) {
    // This function might crash, not sure
    Card &minion = game.getTargetCard();
    int defense = minion.getDefense();

    game.attackMinion(minion, 9999);
    minion.setDefense(defense);

    Player &player = game.getTargetPlayer();
    std::unique_ptr<Minion> returnedMinion = std::make_unique<Minion>(minion);
    player.getHand().addCard(std::move(returnedMinion));
}

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
    
    for (size_t i = 0; i < currentMinions.getSize(); ++i) {
        game.attackMinion(currentMinions.getMinion(i), 2);
    }

    // enemy player
    ActiveMinions &enemyMinions = game.getOtherPlayer().getActiveMinions();
    
    for (size_t i = 0; i < currentMinions.getSize(); ++i) {
        game.attackMinion(enemyMinions.getMinion(i), 2);
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

    for (size_t i = 0; i < activeMinions.getSize(); ++i) {
        Card &minion = activeMinions.getMinion(i);
        minion.setDefense(minion.getDefense() + 1);
    }
}

// Activated Ability
void abilityNovicePyromancer(Game &game) {
    abilityAttackMinion(game);
}

void abilityApprenticeSummoner(Game &game) {
    std::unique_ptr<Card> newMinion = std::make_unique<Minion>("Air Elemental");
    game.playCard(std::move(newMinion));
}

void abilityMasterSummoner(Game &game) {
    for (int i = 0; i < 3; ++i) {
        abilityApprenticeSummoner(game);
    }
}

// Rituals
void abilityDarkRitual(Game &game) {
    Player &player = game.getActivePlayer();
    // player.gainMagic(1);
}

void abilityAuraOfPower(Game &game) {
    Card &minion = game.getTargetCard();
    minion.setAttack(minion.getAttack() + 1);
    minion.setDefense(minion.getDefense() + 1);
}

void abilityStandstill(Game &game) {
    game.attackMinion(game.getTargetCard(), 9999);
}
