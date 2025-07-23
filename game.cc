#include "game.h"

// CONSTANTS
const int START_HP = 20;
const int START_MAGIC = 3;
const std::string NAME_1 = "player1";
const std::string NAME_2 = "player2";
const int MAX_HAND = 5;

Game::Game(std::string name1, std::string name2, std::string deck1, std::string deck2): 
    currP1{true}, p1{name1, START_HP, START_MAGIC, deck1}, p2{name2, START_HP, START_MAGIC, deck2} {}


Player &Game::getActivePlayer() {
    if (currP1) {
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

void Game::discard(int i) {
    getActivePlayer().getHand().removeCard(i);
}

void Game::endTurn() {
    currP1 = !currP1;
}

