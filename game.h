#ifndef GAME_H
#define GAME_H
#include "display.h"
#include "player.h"
#include "subject.h"

class Game {
    Player p1;
    Player p2;
public:

    Game() = default;

    ~Game() = default;

    void setup() {}

    Player getActivePlayer() {}

    void drawCard() {}

    void discard(int i) {}

};

#endif

