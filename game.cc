#include "game.h"

// CONSTANTS
const int START_HP = 20;
const int START_MAGIC = 3;
const std::string NAME_1 = "player1";
const std::string NAME_2 = "player2";

Game::Game(std::string deck1, std::string deck2): 
    currP1{true}, p1{NAME_1, START_HP, START_MAGIC, deck1}, p2{NAME_2, START_HP, START_MAGIC, deck2} {}


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

void drawCard() {
    //if (getActivePlayer().getDeck().removeCard(0))
}

void Game::discard(int i) {
    getActivePlayer().getDeck().removeCard(i);
}

void Game::endTurn() {
    currP1 = !currP1;
}

