#include "game.h"

// CONSTANTS
const int START_HP = 20;
const int START_MAGIC = 3;
const std::string NAME_1 = "player1";
const std::string NAME_2 = "player2";
const int MAX_HAND = 5;
const int MAX_ACTIVE = 5;

Game::Game(std::string name1, std::string name2, std::string deck1, std::string deck2): 
    currP1{true}, p1{name1, START_HP, START_MAGIC, deck1}, p2{name2, START_HP, START_MAGIC, deck2}, 
    currCardIndex{0}, targetCardIndex{0}, currTargetPlayer1{true} {
        startTurn();
    }


Player &Game::getActivePlayer() {
    if (currP1) {
        return p1;
    } else {
        return p2;
    }
}

Player &Game::getOtherPlayer() {
    if (!currP1) {
        return p1;
    } else {
        return p2;
    }
}

Player &Game::getTargetPlayer() {
    if (currTargetPlayer1) {
        return p1;
    } else {
        return p2;
    }
}

Player &Game::getPlayerOne() {
    return p1;
}

Player &Game::getPlayerTwo() {
    return p2;
}

void Game::drawCard() {
    getActivePlayer().drawCard();
}

// For normal play
void Game::playCard(size_t i) {
    if (getActivePlayer().getActiveCardSize() >= MAX_ACTIVE) return;
    getActivePlayer().playCard(i);
    triggerEnter(i); // order matters!
    //getAc->attach();
}

// for summoning
void Game::playCard(std::unique_ptr<Card> min) {
    if (getActivePlayer().getActiveCardSize() >= MAX_ACTIVE) return;
    size_t temp = getActivePlayer().getActiveCardSize();
    getActivePlayer().placeCard(std::move(min));
    triggerEnter(temp); // order matters!
    //min->attach();
}

void Game::discard(int i) {
    getActivePlayer().getHand().removeCard(i);
}

void Game::attackPlayer(size_t i) {
    getActivePlayer().attackPlayer(i, getOtherPlayer());
}

void Game::attackPlayer(size_t i, Player &enemy) {
    getActivePlayer().attackPlayer(i, enemy);
}

void Game::attackMinion(Card &attacker, Card &enemy) {
    getActivePlayer().attackMinion(attacker, enemy);
    // kill all minions which are dead
    getActivePlayer().killMinions();
    getOtherPlayer().killMinions();
}

void Game::attackMinion(Card &enemy, int dmg) {
    enemy.takeDamage(dmg);
    // kill all minions which are dead
    if (getActivePlayer().killMinions()) {
        triggerLeave(currP1);
    }
    if (getOtherPlayer().killMinions()) {
        triggerLeave(!currP1);
    }
}

void Game::attackMinion(size_t i, Player &enemy, size_t j) {
    getActivePlayer().attackMinion(i, enemy, j);
    if (getActivePlayer().killMinions()) {
        triggerLeave(currP1);
    }
    if (getOtherPlayer().killMinions()) {
        triggerLeave(!currP1);
    }
    //if (getActivePlayer().getActiveCard(i).isDead()) getActivePlayer().killMinion(i);
    //if (enemy.getActiveCard(i).isDead()) enemy.killMinion(i);
}

void Game::useAbility(size_t i, bool player1, size_t j) {
    currCardIndex = i;
    targetCardIndex = j;
    if (player1) currTargetPlayer1 = true;
    else currTargetPlayer1 = false;

    // Check
    if (getActiveCard().getAbilityCost() <= 0) return; // just double check to see if its not an active ability
    if (getActiveCard().getAbilityCost() <= getActivePlayer().getMagic()) {
        getActivePlayer().incrementMagic(-getActiveCard().getAbilityCost());
        getActiveCard().useAbility(*this);
    } // add else if you want to do something when they can't afford ability
}

Card &Game::getActiveCard() {
    return getActivePlayer().getActiveCard(currCardIndex);
}

Card &Game::getTargetCard() {
    if (currTargetPlayer1) {
        return getPlayerOne().getActiveCard(targetCardIndex);
    } else {
        return getPlayerTwo().getActiveCard(targetCardIndex);
    }
}

void Game::startTurn() {
    triggerStart();
    getActivePlayer().drawCard(); // draw 1 card at the start of turn
    getActivePlayer().incrementMagic(1);
}

void Game::endTurn() {
    triggerEnd();
    currP1 = !currP1;
    startTurn();
}


// Private Helper Functions

// Subjects and trigger helpers
void Game::triggerStart() {
    if (currP1) {
        startP1.notifyObservers(*this);
    } else {
        startP2.notifyObservers(*this);
    }
}

void Game::triggerEnd() {
    if (currP1) {
        endP1.notifyObservers(*this);
    } else {
        endP2.notifyObservers(*this);
    }
}

void Game::triggerEnter(size_t i) {
    targetCardIndex = i;

    // APNAP
    if (currP1) {
        enterP1.notifyObservers(*this);
        enterP2.notifyObservers(*this);
    } else {
        enterP2.notifyObservers(*this);
        enterP1.notifyObservers(*this);
    }
}

void Game::triggerLeave(bool deadMinP1) {
    if (deadMinP1) {
        leaveP1.notifyObservers(*this);
        leaveP2.notifyObservers(*this);
    } else {
        leaveP2.notifyObservers(*this);
        leaveP1.notifyObservers(*this);
    }
}
