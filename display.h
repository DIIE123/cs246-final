#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>

class Game;

class Display {
  Game &game;
public:
  Display(Game& game);
  virtual ~Display();
  virtual void displayBoard() = 0;
  virtual void displayHand() = 0;
  virtual void inspect() = 0;
};

#endif
