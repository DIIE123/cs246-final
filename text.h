#ifndef TEXT_H
#define TEXT_H
#include <memory>
#include "display.h"
#include "minion.h"

extern const size_t cardWidth;
extern const size_t minionMax;
extern const size_t boardWidth;
extern const size_t boardHeight;

class Text: public Display {
public:
  Text(Game &game);
  ~Text();
  void displayBoard() override;
  void displayHand() override;
  void inspect(std::shared_ptr<Card> minion) override;
};

#endif
