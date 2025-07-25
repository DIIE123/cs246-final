#include "game.h"
#include "type.h"
#include <iostream>

// CONSTANTS
const int START_HP = 20;
const int START_MAGIC = 3;
const int START_CARDS = 5;
const std::string NAME_1 = "player1";
const std::string NAME_2 = "player2";
const int MAX_HAND = 5;
const int MAX_ACTIVE = 5;

Game::Game(bool isTesting, std::string name1, std::string name2, std::string deck1, std::string deck2): 
    isTesting{isTesting}, currP1{true}, p1{name1, START_HP, START_MAGIC, deck1, isTesting}, p2{name2, START_HP, START_MAGIC, deck2, isTesting}, 
    currCardIndex{0}, targetCardIndex{0}, currActivePlayer1{true}, currTargetPlayer1{true}, turnsPassed{0} {
        startTurn();
    }


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

Player &Game::getTargetPlayer() {
    if (currTargetPlayer1) {
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

// For normal play
bool Game::playCard(size_t i) {
    Player &p = getActivePlayer();
    Card &card = p.getHandCard(i);

    if (card.getType() == CardType::Minion) {
        size_t size = p.getActiveCardSize();
        if (size >= MAX_ACTIVE) return false;
        if (card.getCost() <= p.getMagic()) {
            p.incrementMagic(-card.getCost());

            currTargetPlayer1 = currP1;
            std::shared_ptr<Card> temp = p.getHand().removeCard(i);
            p.getActiveMinions().addCard(temp);
            triggerEnter(size); // order matters!
            addTrigger(p.getActiveCardPtr(size));
            return true;
        }
    }
    else if (card.getType() == CardType::Spell) {
        if (card.getIsTarget()) return false;
        return useAbilityInHand(i);
    }
    else if (card.getType() == CardType::Ritual) {
       if (card.getCost() <= p.getMagic()) {
            p.incrementMagic(-card.getCost());

            std::shared_ptr<Card> temp = p.getHand().removeCard(i);
            p.setRitual(temp);
            addTrigger(temp);
            return true;
        }
    }
    return false;
}

// For targeted play
bool Game::playCard(size_t i, bool player1, size_t t) {
    Player &p = getActivePlayer();
    Card &card = p.getHandCard(i);
    Player &target = player1 ? getPlayerOne() : getPlayerTwo();
    ActiveMinions& victim = target.getActiveMinions();
    if (card.getType() == CardType::Spell) {
        if (!card.getIsTarget()) return false;
        return useAbilityInHand(i, player1, t);
    }
    if (card.getType() == CardType::GiantStrength || card.getType() == CardType::Enrage || 
        card.getType() == CardType::Haste || card.getType() == CardType::MagicFatigue || card.getType() == CardType::Silence) {
        victim.useEnchantment(t, card.getType(), getActivePlayer());
        p.getHand().removeCard(i);
    }
    return false;
}

// for summoning
void Game::playCard(std::shared_ptr<Card> min) {
    Player &p = getActivePlayer();
    if (p.getActiveCardSize() >= MAX_ACTIVE) return;

    currTargetPlayer1 = currP1;
    size_t temp = p.getActiveCardSize();
    p.placeCard(min);
    triggerEnter(temp); // order matters!
    addTrigger(p.getActiveCardPtr(temp));
}

bool Game::useCard(size_t i) {
    Player &p = getActivePlayer();
    if (i > p.getActiveCardSize() || p.getActiveCard(i).getIsTarget()) return false;

    return useAbility(i);
}

bool Game::useCard(size_t i, bool player1, size_t t) {
    Player &p = getActivePlayer();
    if (i > p.getActiveCardSize() || !p.getActiveCard(i).getIsTarget()) return false;

    return useAbility(i, player1, t);
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

// attack minion for non-minion entities
void Game::attackMinion(Card &enemy, int dmg) {
    enemy.takeDamage(dmg);
    // kill all minions which are dead
    if (getActivePlayer().killMinions()) {
        removeObservers();
        triggerLeave();
    }
    if (getOtherPlayer().killMinions()) {
        removeObservers();
        triggerLeave();
    }
}

// attack minions for minions
void Game::attackMinion(size_t i, Player &enemy, size_t j) {
    getActivePlayer().attackMinion(i, enemy, j);
    if (getActivePlayer().killMinions()) {
        removeObservers();
        triggerLeave();
    }
    if (getOtherPlayer().killMinions()) {
        removeObservers();
        triggerLeave();
    }
    //if (getActivePlayer().getActiveCard(i).isDead()) getActivePlayer().killMinion(i);
    //if (enemy.getActiveCard(i).isDead()) enemy.killMinion(i);
}

bool Game::useAbility(size_t i, bool player1, size_t j) {
    Card &card = getActiveCard();
    Player &p = getActivePlayer();

    // Check
    if (card.getAbilityCost() <= 0) return false; // just double check to see if its not an active ability
    if (card.getActions() <= 0) return false; // has no more actions
    if (card.getAbilityCost() <= p.getMagic() || isTesting) {
        currCardIndex = i;
        targetCardIndex = j;
        currTargetPlayer1 = player1;

        if (!card.useAbility(*this)) return false;

        p.incrementMagic(-card.getAbilityCost());
        
        card.decreaseActions();
        return true;
    } // add else if you want to do something when they can't afford ability
    return false;
}

bool Game::useAbilityInHand(size_t i, bool player1, size_t j) {
    Player &p = getActivePlayer();
    Card &card = p.getHandCard(i);

    // Check
    if (card.getAbilityCost() <= getActivePlayer().getMagic() || isTesting) {
        targetCardIndex = j;
        currTargetPlayer1 = player1;
        if (!card.useAbility(*this)) return false;
        p.incrementMagic(-card.getAbilityCost());
        p.getHand().removeCard(i);
        return true;
    } // add else if you want to do something when they can't afford ability

    return false;
}

Card &Game::getActiveCard() {
    if (currActivePlayer1) {
        return getPlayerOne().getActiveCard(currCardIndex);
    } else {
        return getPlayerTwo().getActiveCard(currCardIndex);
    }
}

std::shared_ptr<Card> Game::getActiveCardPtr() {
    if (currActivePlayer1) {
        return getPlayerOne().getActiveCardPtr(currCardIndex);
    } else {
        return getPlayerTwo().getActiveCardPtr(currCardIndex);
    }
}

Card &Game::getTargetCard() {
    if (currTargetPlayer1) {
        return getPlayerOne().getActiveCard(targetCardIndex);
    } else {
        return getPlayerTwo().getActiveCard(targetCardIndex);
    }
}

std::shared_ptr<Card> Game::getTargetCardPtr() {
    if (currTargetPlayer1) {
        return getPlayerOne().getActiveCardPtr(targetCardIndex);
    } else {
        return getPlayerTwo().getActiveCardPtr(targetCardIndex);
    }
}

void Game::setActiveIndex(size_t i) {
    currCardIndex = i;
}

void Game::startTurn() {
    if (turnsPassed >= 2) {
        triggerStart();
        getActivePlayer().drawCard(); // draw 1 card at the start of turn
        getActivePlayer().incrementMagic(1);
        getActivePlayer().resetActions();
    }
    else {
        ++turnsPassed;
        for (int i = 0; i < START_CARDS; ++i) {
            getActivePlayer().drawCard();
        }
    }
}

void Game::endTurn() {
    triggerEnd();
    currP1 = !currP1;
    currActivePlayer1 = currP1;
    startTurn();
}


// Private Helper Functions

// Subjects and trigger helpers
void Game::triggerStart() {
    if (currP1) {
        startP1.notifyObservers(*this);
    } else {
        startP2.notifyObservers(*this);
    }
}

void Game::triggerEnd() {
    if (currP1) {
        endP1.notifyObservers(*this);
    } else {
        endP2.notifyObservers(*this);
    }
}

void Game::triggerEnter(size_t i) {
    // std::cout << "enter trigger" << std::endl;
    currTargetPlayer1 = currP1;
    targetCardIndex = i;
    // std::cout << "entered minion is " << getTargetCard().getName() << std::endl;

    // APNAP
    if (currP1) {
        enterP1.notifyObservers(*this);
        currActivePlayer1 = !currActivePlayer1;
        enterP2.notifyObservers(*this);
        currActivePlayer1 = !currActivePlayer1;
    } else {
        enterP2.notifyObservers(*this);
        currActivePlayer1 = !currActivePlayer1;
        enterP1.notifyObservers(*this);
        currActivePlayer1 = !currActivePlayer1;
    }
}

void Game::triggerLeave() {
    if (currP1) {
        leaveP1.notifyObservers(*this);
        currActivePlayer1 = !currActivePlayer1;
        leaveP2.notifyObservers(*this);
        currActivePlayer1 = !currActivePlayer1;
    } else {
        leaveP2.notifyObservers(*this);
        currActivePlayer1 = !currActivePlayer1;
        leaveP1.notifyObservers(*this);
        currActivePlayer1 = !currActivePlayer1;
    }
}

void Game::addTrigger(std::shared_ptr<Card> minion) {
    if (currP1) {
        if (minion->getTriggerType() == TriggerType::Start) startP1.attach(minion);
        else if (minion->getTriggerType() == TriggerType::End) endP1.attach(minion);
        else if (minion->getTriggerType() == TriggerType::Enter) enterP1.attach(minion);
        else if (minion->getTriggerType() == TriggerType::Leave) leaveP1.attach(minion);
    }
    else {
        if (minion->getTriggerType() == TriggerType::Start) startP2.attach(minion);
        else if (minion->getTriggerType() == TriggerType::End) endP2.attach(minion);
        else if (minion->getTriggerType() == TriggerType::Enter) enterP2.attach(minion);
        else if (minion->getTriggerType() == TriggerType::Leave) leaveP2.attach(minion);
    }
}

void Game::removeObservers() {
    startP1.removeObservers();
    endP1.removeObservers();
    enterP1.removeObservers();
    leaveP1.removeObservers();
    startP2.removeObservers();
    endP2.removeObservers();
    enterP2.removeObservers();
    leaveP2.removeObservers();
}
