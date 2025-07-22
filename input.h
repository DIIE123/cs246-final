#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <string>

class Game;

class Input {
  Game &game;
  bool isTesting;
public:
  Input(Game &game, bool isTesting);
  ~Input();
  bool handleCommand(std::istream &istr = std::cin);
};

#endif


