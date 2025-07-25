#ifndef GAME_H
#define GAME_H
#include <string>
#include <memory>
#include "display.h"
#include "player.h"
#include "subject.h"
#include "ritual.h"
#include "subject.h"

class Game {
    // Fields
    bool isTesting;
    bool currP1;
    Player p1;
    Player p2;
    size_t currCardIndex;
    size_t targetCardIndex;
    bool currTargetPlayer1;

    // Trigger Fields
    Subject startP1; // start turn
    Subject endP1; // end turn
    Subject enterP1; // enter play (join the board)
    Subject leaveP1; // leave play (dies or leaves the board)
    Subject startP2;
    Subject endP2;
    Subject enterP2;
    Subject leaveP2;

private:

    // Subjects and trigger helpers
    void triggerStart();

    void triggerEnd();

    void triggerEnter(size_t i);

    void triggerLeave(bool deadMinP1);

    void addTrigger(std::shared_ptr<Card> minion);

    void removeObservers();

public:

    Game(bool isTesting, std::string name1, std::string name2, std::string deck1, std::string deck2);

    ~Game() = default;

    Player &getActivePlayer();

    Player &getOtherPlayer();

    // For ability target
    Player &getTargetPlayer();

    Player &getPlayerOne();

    Player &getPlayerTwo();

    void drawCard();

    void playCard(size_t i);

    void playCard(size_t i, Player &enemy, size_t t);

    void playCard(std::shared_ptr<Card> min);

    void useCard(size_t i);
    
    void useCard(size_t i, Player &enemy, size_t t);

    void discard(int i);

    void attackPlayer(size_t i);

    void attackPlayer(size_t i, Player &enemy);

    void attackMinion(Card &enemy, int dmg);

    void attackMinion(size_t i, Player &enemy, size_t j);

    void useAbility(size_t i, bool player1 = true, size_t j = 0);

    Card &getActiveCard();

    std::shared_ptr<Card> getActiveCardPtr();

    Card &getTargetCard();

    std::shared_ptr<Card> getTargetCardPtr();

    void setActiveIndex(size_t i);

    void startTurn();

    // end the current player's turn
    void endTurn();

};

#endif

