#include "text.h"
#include "ascii_graphics.h"
#include "game.h"
#include "info.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>


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
  size_t size = row.size();
  size_t offset = 0;
  while (size >= minionMax) {
    for (size_t i = 0; i < rowHeight; i++) {
      std::string line;
      if (Withborder) {
        line += EXTERNAL_BORDER_CHAR_UP_DOWN;
      }
      for (size_t j = 0; j < minionMax; j++) {
        line += row[offset + j][i];
      }
      if (Withborder) {
        line += EXTERNAL_BORDER_CHAR_UP_DOWN;
      }
      std::cout << line << std::endl;
    }
    size -= minionMax;
    offset += minionMax;
  }
  if (size == 0) {
    return;
  }
  for (size_t i = 0; i < rowHeight; i++) {
    std::string line;
    if (Withborder) {
      line += EXTERNAL_BORDER_CHAR_UP_DOWN;
    }
    for (size_t j = 0; j < size; j++) {
      line += row[offset + j][i];
    }
    if (Withborder) {
      line += EXTERNAL_BORDER_CHAR_UP_DOWN;
    }
    std::cout << line << std::endl;
  }
}

static void printCentreGraphic() {
  for (auto& it: CENTRE_GRAPHIC) {
    std::cout << it << std::endl;
  }
}

static void printCard(card_template_t c) {
  for (auto& it: c) {
    std::cout << it << std::endl;
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
  // temporary!!
  playerOneRow.emplace_back(CARD_TEMPLATE_BORDER);
  playerOneRow.emplace_back(CARD_TEMPLATE_EMPTY);
  card_template_t playerOne = display_player_card(1, game.getPlayerOne().getName(), game.getPlayerOne().getHealth(), game.getPlayerOne().getMagic());
  playerOneRow.emplace_back(playerOne);
  playerOneRow.emplace_back(CARD_TEMPLATE_EMPTY);
  // Print graveyard
  std::shared_ptr<CardInfo> grave1 = game.getPlayerOne().getGraveyard().getInfo();
  if (!grave1) {
    playerOneRow.emplace_back(CARD_TEMPLATE_BORDER);
  } else if (grave1->activationCost <= 0) {
    playerOneRow.emplace_back(display_minion_triggered_ability(grave1->name, grave1->cost, grave1->damage, grave1->health, grave1->description));
  } else {
    playerOneRow.emplace_back(display_minion_activated_ability(grave1->name, grave1->cost, grave1->damage, grave1->health, grave1->activationCost, grave1->description));
  }
  displayRow(playerOneRow, true);


  // Print top player minions
  std::vector<card_template_t> playerOneMinions;
  std::vector<std::shared_ptr<CardInfo>> information1 = game.getPlayerOne().getActiveMinions().getInfo();
  for (size_t i = 0; i < minionMax; i++) {
    if(i < game.getPlayerOne().getActiveCardSize()) {
      if (information1[i]->activationCost <= 0) {
        playerOneMinions.emplace_back(display_minion_triggered_ability(information1[i]->name, information1[i]->cost, 
          information1[i]->damage, information1[i]->health, information1[i]->description));
        continue;
      }
      playerOneMinions.emplace_back(display_minion_activated_ability(information1[i]->name, information1[i]->cost, 
        information1[i]->damage, information1[i]->health, information1[i]->activationCost, information1[i]->description));
      continue;
    }
    playerOneMinions.emplace_back(CARD_TEMPLATE_EMPTY);
  }
  displayRow(playerOneMinions, true);
  // Print middle
  printCentreGraphic();

  // Print bottom player minions
  std::vector<card_template_t> playerTwoMinions;
  std::vector<std::shared_ptr<CardInfo>> information2 = game.getPlayerTwo().getActiveMinions().getInfo();
  for (size_t i = 0; i < minionMax; i++) {
    if(i < game.getPlayerTwo().getActiveCardSize()) {
      if (information2[i]->activationCost <= 0) {
        playerTwoMinions.emplace_back(display_minion_triggered_ability(information2[i]->name, information2[i]->cost, 
          information2[i]->damage, information2[i]->health, information2[i]->description));
        continue;
      }
      playerTwoMinions.emplace_back(display_minion_activated_ability(information2[i]->name, information2[i]->cost, 
        information2[i]->damage, information2[i]->health, information2[i]->activationCost, information2[i]->description));
      continue;
    }
    playerTwoMinions.emplace_back(CARD_TEMPLATE_EMPTY);
  }
  displayRow(playerTwoMinions, true);

  // Print bottom player
  std::vector<card_template_t> playerTwoRow;
  playerTwoRow.emplace_back(CARD_TEMPLATE_BORDER);
  playerTwoRow.emplace_back(CARD_TEMPLATE_EMPTY);
  card_template_t playerTwo = display_player_card(2, game.getPlayerTwo().getName(), game.getPlayerTwo().getHealth(), game.getPlayerTwo().getMagic());
  playerTwoRow.emplace_back(playerTwo);
  playerTwoRow.emplace_back(CARD_TEMPLATE_EMPTY);
  std::shared_ptr<CardInfo> grave2 = game.getPlayerTwo().getGraveyard().getInfo();
  if (!grave2) {
    playerTwoRow.emplace_back(CARD_TEMPLATE_BORDER);
  } else if (grave2->activationCost <= 0) {
    playerTwoRow.emplace_back(display_minion_triggered_ability(grave2->name, grave2->cost, grave2->damage, grave2->health, grave2->description));
  } else {
    playerTwoRow.emplace_back(display_minion_activated_ability(grave2->name, grave2->cost, grave2->damage, grave2->health, grave2->activationCost, grave2->description));
  }
  displayRow(playerTwoRow, true);
  // Print bottom border
  printBottomBorder();
}

void Text::displayHand() {
  std::vector<card_template_t> currentHand;
  size_t limit = game.getActivePlayer().getHandSize();
  std::vector<std::shared_ptr<CardInfo>> information = game.getActivePlayer().getHand().getInfo();
  for (size_t i = 0; i < limit; i++) {
    CardType type = information[i]->getType();
    if (type == CardType::Minion) {
      if (information[i]->activationCost <= 0) {
        card_template_t temp = display_minion_triggered_ability(information[i]->name, information[i]->cost, 
          information[i]->damage, information[i]->health, information[i]->description);
        currentHand.emplace_back(temp);
        continue;
      }
      card_template_t temp = display_minion_activated_ability(information[i]->name, information[i]->cost, 
        information[i]->damage, information[i]->health, information[i]->activationCost, information[i]->description);
      currentHand.emplace_back(temp);
      continue;
    }
    if (type == CardType::Spell) {
      card_template_t temp = display_spell(information[i]->name, information[i]->cost, information[i]->description);
      currentHand.emplace_back(temp);
    }
  }
  displayRow(currentHand, false);
}

void Text::inspect(std::shared_ptr<Card> minion) {
  std::shared_ptr<Card> head = minion;
  std::vector<card_template_t> information;

  while (1) {
    // Print Minion. Exit.
    if (head->getType() == CardType::Minion) {
      if (head->getAbilityCost() <= 0) {
        card_template_t temp = display_minion_triggered_ability(head->getName(), head->getCost(), 
          head->getAttack(), head->getDefense(), head->getAbilityDesc());
        printCard(temp);
        break;
      }
      card_template_t temp = display_minion_activated_ability(head->getName(), head->getCost(), 
        head->getAttack(), head->getDefense(), head->getAbilityCost(), head->getAbilityDesc());
      printCard(temp);
      break;
    }
    if (head->getType() == CardType::GiantStrength || 
        head->getType() == CardType::Enrage) {
      card_template_t temp = display_enchantment_attack_defence(head->getName(), head->getCost(), head->getAbilityDesc(), head->getAttackString(), head->getDefenseString());
      information.emplace_back(temp);
      continue;
    }
    card_template_t temp = display_enchantment(head->getName(), head->getCost(), head->getAbilityDesc());
    information.emplace_back(temp);
    head = head->getPointer();
  }
  // Print Enchantments
  std::reverse(information.begin(), information.end());
  displayRow(information, false);
}

