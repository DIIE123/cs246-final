#ifndef GAME_H
#define GAME_H
#include <string>
#include <memory>
#include "display.h"
#include "player.h"
#include "subject.h"
#include "ritual.h"

class Game {
    bool currP1;
    Player p1;
    Player p2;
    std::shared_ptr<Card> curr;
    std::shared_ptr<Card> target;
public:

    Game(std::string name1, std::string name2, std::string deck1, std::string deck2);

    ~Game() = default;

    Player &getActivePlayer();

    Player &getOtherPlayer();

    Player &getPlayerOne();

    Player &getPlayerTwo();

    void drawCard();

    void playCard(size_t i);

    void playCard(Card &min);

    void discard(int i);

    void attackPlayer(size_t i);

    void attackPlayer(size_t i, Player &enemy);
    
    void attackMinion(Minion &attacker, Minion &enemy);

    void attackMinion(Minion &enemy, int dmg);

    void attackMinion(size_t i, Player &enemy, size_t j);

    std::shared_ptr<Card> getActiveCard();

    std::shared_ptr<Card> getTargetCard();

    // end the current player's turn
    void endTurn();

};

#endif

