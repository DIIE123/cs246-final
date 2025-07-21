#include "game.h"


Player Game::getActivePlayer() {
    
}

void drawCard() {
    //if (getActivePlayer().getDeck().removeCard(0))
}

void Game::discard(int i) {
    getActivePlayer().getDeck().removeCard(i);
}

