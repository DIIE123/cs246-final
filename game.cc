#include "game.h"

// CONSTANTS
const int START_HP = 20;
const int START_MAGIC = 3;
const std::string NAME_1 = "player1";
const std::string NAME_2 = "player2";
const int MAX_HAND = 5;
const int MAX_ACTIVE = 5;

Game::Game(std::string name1, std::string name2, std::string deck1, std::string deck2): 
    currP1{true}, p1{name1, START_HP, START_MAGIC, deck1}, p2{name2, START_HP, START_MAGIC, deck2} {}


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

Player &Game::getPlayerOne() {
    return p1;
}

Player &Game::getPlayerTwo() {
    return p2;
}

void Game::drawCard() {
    getActivePlayer().drawCard();
}

void Game::playCard(size_t i) {
    if (getActivePlayer().getActiveCardSize() >= MAX_ACTIVE) return;
    getActivePlayer().playCard(i);
}

void Game::playCard(Card &min) {
    if (getActivePlayer().getActiveCardSize() >= MAX_ACTIVE) return;
    getActivePlayer().placeCard(min);
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
}

void Game::attackMinion(Card &enemy, int dmg) {
    enemy.takeDamage(dmg);
}

void Game::attackMinion(size_t i, Player &enemy, size_t j) {
    getActivePlayer().attackMinion(i, enemy, j);
}

Card &Game::getActiveCard() {
    return *curr;
}

Card &Game::getTargetCard() {
    return *target;
}

void Game::endTurn() {
    currP1 = !currP1;
}

