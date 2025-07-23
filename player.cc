#include "player.h"
#include <iostream>

// CONSTANTS
const int MAX_HAND = 5;

Player::Player(std::string name, int hp, int mp, std::string deckFile): 
    name{name}, health{hp}, mana{mp}, deck{}, hand{}, activeMinions{} {
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
    std::unique_ptr<Card> temp = std::move(hand.removeCard(i));
    if (temp->getType() == CardType::Minion) {
        activeMinions.addCard(std::move(temp));
    }
}

void playCard(size_t i, Player &enemy, size_t t) {
    // work on this later
}

void Player::drawCard() {
    if (getHandSize() >= MAX_HAND) {
        
        // Can't draw anymore cards; no space
        return;
    }
    if (deck.getSize() == 0) {
        // No more cards in deck
        return;
    }
    hand.addCard(deck.removeCard(0));
}

Card &Player::getActiveMinion(size_t i) {
    return activeMinions.getMinion(i);
}

void Player::attackPlayer(size_t i, Player &enemy) {
    //getActiveMinion(i).doDamage(enemy);
}

void Player::attackMinion(size_t i, Player &enemy, size_t j) {
    //getActiveMinion(i).doDamage(enemy.getActiveMinion(j));
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
