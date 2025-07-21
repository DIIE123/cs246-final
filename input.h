#include <iostream>;
#include <string>

class Game;

class Input {
  Game &game;
  bool isTesting;
public:
  Input(Game &game, bool isTesting);
  ~Input();
  void handleCommand(istream &istr = std::cin);
};

