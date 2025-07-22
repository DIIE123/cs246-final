#include "player.h"

Player::Player(int hp, int mp): health{hp}, mana{mp} {
    
}
// pass a file name to deck or smth

bool Player::takeDamage(int dmg) {
    health -= dmg;
    if (health <= 0) {
        health = 0;
        return true;
    }
    return false;
}

void createDeck() {} // do we need this?

size_t Player::getHandSize() {
    //return hand.getSize();
}

Hand &Player::getHand() {
    return hand;
}

Deck &Player::getDeck() {
    return deck;
}
