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

void Player::placeCard(std::shared_ptr<Card> min) {
    activeMinions.addCard(min);
}

Card &Player::getActiveCard(size_t i) {
    return activeMinions.getCard(i);
}

Card &Player::getHandCard(size_t i) {
    return hand.getCard(i);
}

std::shared_ptr<Card> Player::getActiveCardPtr(size_t i) {
    return activeMinions.getCardPtr(i);
}

std::shared_ptr<Card> Player::getHandCardPtr(size_t i) {
    return hand.getCardPtr(i);
}

ActiveMinions &Player::getActiveMinions() {
    return activeMinions;
}

Graveyard &Player::getGraveyard() {
    return graveyard;
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

bool Player::killMinions() {
    bool killed = false;
    for (size_t i = 0; i < activeMinions.getSize(); i++) {
        if (activeMinions.getCard(i).isDead()) {
            graveyard.addCard(std::make_shared<Minion>(activeMinions.removeCard(i)->getName()));
            killed = true;
            --i;
        }
    }
    return killed;
}


// Deal with magic
void Player::incrementMagic(int i) {
    magic += i;

    if (magic < 0) magic = 0;
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

std::shared_ptr<Card> Player::getRitual() {
    return ritual;
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

bool Player::operator!=(const Player &other) const {
    return name != other.name || health != other.health || magic != other.magic;
}

