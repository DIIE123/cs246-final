#ifndef INPUT_H
#define INPUT_H
#include "game.h"
#include "text.h"
#include <iostream>
#include <string>

class Input {
  Game &game;
  Text &text;
  bool isTesting;
public:
  Input(Game &game, Text& text, bool isTesting);
  ~Input();
  bool handleCommand(std::istream &istr = std::cin);
};

#endif


