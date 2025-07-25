#ifndef DISPLAY_H
#define DISPLAY_H
#include "minion.h"
#include <string>

class Game;

class Display {
protected:
  Game &game;
public:
  Display(Game &game);
  virtual ~Display();
  virtual void displayBoard() = 0;
  virtual void displayHand() = 0;
  virtual void inspect(std::shared_ptr<Card> minion) = 0;
};

#endif
