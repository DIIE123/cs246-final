#include "player.h"
#include <iostream>

// CONSTANTS
const int MAX_HAND = 5;
const int MAX_ACTIVE = 5;

Player::Player(std::string name, int hp, int mp, std::string deckFile): 
    name{name}, health{hp}, magic{mp}, deck{}, hand{}, activeMinions{} {
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

// Assumed to be affordable and valid from Game
bool Player::playCard(size_t i) {
    std::unique_ptr<Card> temp = std::move(hand.removeCard(i));
    if (temp->getType() == CardType::Minion) {
        activeMinions.addCard(std::move(temp));
        return true;
    } else if (temp->getType() == CardType::Spell) {
        
    }
    return false;
}

bool Player::playCard(size_t i, Player &enemy, size_t t) {
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

void Player::placeCard(std::unique_ptr<Card> min) {
    activeMinions.addCard(std::move(min));
}

void Player::playMinion(size_t i) {
    // do this
}

void Player::playSpell(size_t i) {
    // do this
}

void Player::playSpell(size_t i, Player &enemy, size_t j) {
    // do this
}

void Player::playEnchant(size_t i, size_t j) {

}

void Player::playRitual(size_t i) {
    
}

Card &Player::getActiveCard(size_t i) {
    return activeMinions.getMinion(i);
}

ActiveMinions &Player::getActiveMinions() {
    return activeMinions;
}

size_t Player::getActiveCardSize() {
    return activeMinions.getSize();
}

// Attacking
void Player::attackPlayer(size_t i, Player &enemy) {
    getActiveCard(i).doDamage(enemy);
    getActiveCard(i).decreaseActions();
}

void Player::attackMinion(Card &attacker, Card &enemy) {
    attacker.doDamage(enemy);
    attacker.decreaseActions();
}

void Player::attackMinion(size_t i, Player &enemy, size_t j) {
    getActiveCard(i).doDamage(enemy.getActiveCard(j));
    getActiveCard(i).decreaseActions();
}

void Player::killMinion(size_t i) {
    activeMinions.removeCard(i);
}

bool Player::killMinions() {
    bool killed = false;
    for (size_t i = 0; i < activeMinions.getSize(); i++) {
        if (activeMinions.getMinion(i).isDead()) {
            activeMinions.removeCard(i);
            killed = true;
        }
    }
    return killed;
}


// Deal with magic
void Player::incrementMagic(int i) {
    magic += i;
}

void Player::setMagic(int i) {
    magic = i;
}

void Player::resetActions() {
    for (size_t i = 0; i < activeMinions.getSize(); i++) {
        getActiveCard(i).resetActions();
    }
}

// Getters for important fields
size_t Player::getHandSize() {
    return hand.getSize();
}

Hand &Player::getHand() {
    return hand;
}

Deck &Player::getDeck() {
    return deck;
}

std::unique_ptr<Card> Player::getRitual() {
    return std::move(ritual);
}

// health, magic, name getters
int Player::getHealth() {
    return health;
}

int Player::getMagic() {
    return magic;
}

std::string Player::getName() {
    return name;
}

