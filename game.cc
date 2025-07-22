#include "game.h"

void Game::setup() {
    //p1 = unique_ptr<Player> play1{100, 100};
}

Player Game::getActivePlayer() {
    // work on this next
}

void drawCard() {
    //if (getActivePlayer().getDeck().removeCard(0))
}

void Game::discard(int i) {
    getActivePlayer().getDeck().removeCard(i);
}

