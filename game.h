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

public:

    Game(std::string name1, std::string name2, std::string deck1, std::string deck2);

    ~Game() = default;

    Player &getActivePlayer();

    Player &getOtherPlayer();

    // For ability target
    Player &getTargetPlayer();

    Player &getPlayerOne();

    Player &getPlayerTwo();

    void drawCard();

    void playCard(size_t i);

    void playCard(std::unique_ptr<Card> min);

    void discard(int i);

    void attackPlayer(size_t i);

    void attackPlayer(size_t i, Player &enemy);
    
    void attackMinion(Card &attacker, Card &enemy);

    void attackMinion(Card &enemy, int dmg);

    void attackMinion(size_t i, Player &enemy, size_t j);

    void useAbility(size_t i, bool player1, size_t j);

    Card &getActiveCard();

    Card &getTargetCard();

    void startTurn();

    // end the current player's turn
    void endTurn();

};

#endif

