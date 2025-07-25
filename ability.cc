#include "ability.h"
#include "minion.h"
#include "player.h"
#include "game.h"

const int MAX_SIZE = 5;

// Abstract Abilities
bool abilityAttackMinion(Game &game, int damage = 1) {
    game.attackMinion(game.getTargetCard(), damage);
    return true;
}

// Spells
bool abilityBanish(Game &game) {
    return abilityAttackMinion(game, game.getTargetCard().getDefense());
}

bool abilityUnsummon(Game &game) {
    Player &player = game.getTargetPlayer();
    if (player.getHandSize() >= MAX_SIZE) return false;

    std::shared_ptr<Card> minion = game.getTargetCardPtr();
    int defense = minion->getDefense();

    // Kill card
    game.attackMinion(*minion, defense);
    minion->setDefense(defense);

    // Add to player hand
    player.getGraveyard().removeTopCard();
    player.getHand().addCard(minion);

    return true;
}

bool abilityRecharge(Game &game) {
    auto ritual = game.getActivePlayer().getRitual();
    if (!ritual) return false;
    ritual->setDefense(ritual->getDefense() + 3);

    return true;
}

bool abilityDisenchant(Game &game) { return false; }

bool abilityRaiseDead(Game &game) {
    Player &player = game.getActivePlayer();
    std::shared_ptr<Card> minion = player.getGraveyard().removeTopCard();

    // Check if no minion in graveyard
    if (!minion) return false;

    // Add to player hand
    minion->setDefense(1);
    player.getHand().addCard(minion);

    return true;
}

bool abilityBlizzard(Game &game) {
    // current player
    ActiveMinions &currentMinions = game.getActivePlayer().getActiveMinions();
    
    for (size_t i = 0; i < currentMinions.getSize(); ++i) {
        currentMinions.getCard(i).setDefense(currentMinions.getCard(i).getDefense() - 2);
    }
    if (currentMinions.getSize() > 0) game.attackMinion(currentMinions.getCard(0), 0);

    // enemy player
    ActiveMinions &enemyMinions = game.getOtherPlayer().getActiveMinions();
    
    for (size_t i = 0; i < enemyMinions.getSize(); ++i) {
        enemyMinions.getCard(i).setDefense(enemyMinions.getCard(i).getDefense() - 2);
    }
    if (enemyMinions.getSize() > 0) game.attackMinion(enemyMinions.getCard(0), 0);

    return true;
}

// Minions
// Triggered Ability
bool abilityBoneGolem(Game &game) {
    Card &minion = game.getActiveCard();
    minion.setAttack(minion.getAttack() + 1);
    minion.setDefense(minion.getDefense() + 1);

    return true;
}

bool abilityFireElemental(Game &game) {
    if (game.getActivePlayer() != game.getActiveCard().getPlayer()) {
        abilityAttackMinion(game);
    }

    return true;
}

bool abilityPotionSeller(Game &game) {
    ActiveMinions &activeMinions = game.getActivePlayer().getActiveMinions();

    for (size_t i = 0; i < activeMinions.getSize(); ++i) {
        Card &minion = activeMinions.getCard(i);
        minion.setDefense(minion.getDefense() + 1);
    }

    return true;
}

// Activated Ability
bool abilityNovicePyromancer(Game &game) {
    return abilityAttackMinion(game);
}

bool abilityApprenticeSummoner(Game &game) {
    Player &p = game.getActivePlayer();
    if (p.getActiveCardSize() >= MAX_SIZE) return false;

    std::shared_ptr<Card> newMinion = std::make_shared<Minion>("Air Elemental", p);
    game.playCard(newMinion);
    return true;
}

bool abilityMasterSummoner(Game &game) {
    const int NUM_SUMMONS = 3;
    Player &p = game.getActivePlayer();
    if (p.getActiveCardSize() >= MAX_SIZE) return false;

    for (int i = 0; i < NUM_SUMMONS; ++i) {
        abilityApprenticeSummoner(game);
    }

    return true;
}

// Rituals
bool abilityDarkRitual(Game &game) {
    Player &player = game.getActivePlayer();
    player.incrementMagic(1);
    return true;
}

bool abilityAuraOfPower(Game &game) {
    if (!(game.getActivePlayer() != game.getActiveCard().getPlayer())) {
        Card &minion = game.getTargetCard();
        minion.setAttack(minion.getAttack() + 1);
        minion.setDefense(minion.getDefense() + 1);
        return true;
    }
    return false;
}

bool abilityStandstill(Game &game) {
    game.attackMinion(game.getTargetCard(), game.getTargetCard().getDefense());
    return true;
}
