#ifndef GAME_H
#define GAME_H
#include <string>
#include "display.h"
#include "player.h"
#include "subject.h"

class Game {
    bool currP1;
    Player p1;
    Player p2;
public:

    Game(std::string name1, std::string name2, std::string deck1, std::string deck2);

    ~Game() = default;

    Player &getActivePlayer();

    Player &getOtherPlayer();

    Player &getPlayerOne();

    Player &getPlayerTwo();

    void drawCard();

    void discard(int i);

    //void attackPlayer(size_t i, Player &enemy);

    //void attackMinion(size_t i, Player &enemy, size_t j);

    // end the current player's turn
    void endTurn();

};

#endif

