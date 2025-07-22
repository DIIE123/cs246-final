#include "player.h"


Player::Player(std::string name, int hp, int mp, std::string deckFile): 
    name{name}, health{hp}, mana{mp}, deck{} {
        deck.createDeck(deckFile);
        deck.shuffle();
    }

bool Player::takeDamage(int dmg) {
    health -= dmg;
    if (health <= 0) {
        health = 0;
        return true;
    }
    return false;
}

void Player::playCard(size_t i) {
    activeMinions.emplace_back(hand.removeCard(i));
}

size_t Player::getActiveMinions() {
    return activeMinions.size();
}

size_t Player::getHandSize() {
    return hand.getSize();
}

Hand &Player::getHand() {
    return hand;
}

Deck &Player::getDeck() {
    return deck;
}
