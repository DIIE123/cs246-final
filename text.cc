#ifndef TEXT_H
#define TEXT_H
#include "text.h"
#include "ascii_graphics.h"
#include <iostream>
#include <string>
#include <vector>


const size_t cardWidth = 33;
const size_t minionMax = 5;
const size_t boardWidth = minionMax * cardWidth;
const size_t rowHeight = 11;


Text::Text(Game &game): Display{game} {}

Text::~Text() {}

static void printTopBorder() {
  std::string topBorder;
  topBorder += EXTERNAL_BORDER_CHAR_TOP_LEFT;
  for (size_t i = 0; i < boardWidth; i++) {
    topBorder += EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
  }
  topBorder += EXTERNAL_BORDER_CHAR_TOP_RIGHT;
  std::cout << topBorder << std::endl;
}

static void printBottomBorder() {
  std::string bottomBorder;
  bottomBorder += EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
  for (size_t i = 0; i < boardWidth; i++) {
    bottomBorder += EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
  }
  bottomBorder += EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT;
  std::cout << bottomBorder << std::endl;
}

static void displayRow(std::vector<card_template_t> row, bool Withborder) {
  for (size_t i = 0; i < rowHeight; i++) {
    std::string line;
    if (Withborder) {
      line += EXTERNAL_BORDER_CHAR_UP_DOWN;
    }
    for (size_t j = 0; j < row.size(); j++) {
      line += row[j][i];
    }
    if (Withborder) {
      line += EXTERNAL_BORDER_CHAR_UP_DOWN;
    }
    std::cout << line << std::endl;
  }
}

static void printCentreGraphic() {
  for (auto it = CENTRE_GRAPHIC.begin(); it != CENTRE_GRAPHIC.end(); it++) {
    std::string line;
    line += EXTERNAL_BORDER_CHAR_UP_DOWN;
    line += *it;
    line += EXTERNAL_BORDER_CHAR_UP_DOWN;
    std::cout << line << std::endl;
  }
}

void Text::displayBoard() {
  // Print top border
  printTopBorder();
  
  // Print top player
  std::vector<card_template_t> playerOneRow;
  card_template_t ritualOne;
  // if (game.playerOne.activeRitual) {
  //   ritual1 = display_ritual(etc)
  // } else {
  //   ritual1 = CARD_TEMPLATE_EMPTY;
  //  }
  // playerOneRow.emplace_back(ritual1);
  playerOneRow.emplace_back(CARD_TEMPLATE_EMPTY);
  // card_template_t playerOne = display_player_card(etc);
  // playerOneRow.emplace_back(playerOne);
  playerOneRow.emplace_back(CARD_TEMPLATE_EMPTY);



  // Print top player minions
  std::vector<card_template_t> playerOneMinions;
  for (size_t i = 0; i < minionMax; i++) {
    // if(i < minions.size()) {
    //   
    //   continue;
    // }
    playerOneMinions.emplace_back(CARD_TEMPLATE_EMPTY);
  }
  // Print middle
  printCentreGraphic();

  // Print bottom player minions
  
  // Print bottom player

  // Print bottom border
  printBottomBorder();
}

void Text::displayHand() {
  // displayRow(deck, false);
}

void Text::inspect(Minion &m) {
  // Print Minion
  
  // Print Enchantments
  

}

#endif
