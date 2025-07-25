#include "input.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Input::Input(Game &game, Text &text, bool isTesting): game{game}, text{text}, isTesting{isTesting}
{}

Input::~Input() {}

bool Input::handleCommand(istream &istr) {
  string s;
  if (!getline(istr, s)) {
    // No more arguments
    return true;
    // Empty command
  }
  istringstream iss{s};
  string command;
  if (!(iss >> command)) {
    // Ignore empty line
    return true;
  }
  if (command == "help") {
    cout << "Commands:" << endl;
    cout << "help -- Display this message." << endl;
    cout << "end -- End the current player’s turn." << endl;
    cout << "quit -- End the game." << endl;
    cout << "attack minion other-minion -- Orders minion to attack other-minion." << endl;
    cout << "attack minion -- Orders minion to attack the opponent." << endl;
    cout << "play card [target-player target-card] -- Play card, optionally targeting ";
    cout << "target-card owned by target-player." << endl;
    cout << "use minion [target-player target-card] -- Use minion’s special ability, ";
    cout << "optionally targeting target-card owned by target-player." << endl;
    cout << "inspect minion -- View a minion’s card and all enchantments on that minion." << endl;
    cout << "hand -- Describe all cards in your hand." << endl;
    cout << "board -- Describe all cards on the board." << endl;
    return true;
  }
  if (command == "end"){
    if (iss >> command) {
      cout << "'end' takes no subsequent arguments. Type 'help' for more details." << std::endl;
      return true;
    }
    game.endTurn();
    return true;
  }
  if (command == "quit") {
    if (iss >> command) {
      cout << "'quit' takes no subsequent arguments. Type 'help' for more details." << std::endl;
      return true;
    }
    return false;
  }
  if (command == "draw") {
    if (iss >> command) {
      cout << "'draw' takes no subsequent arguments. Type 'help' for more details." << std::endl;
      return true;
    }
    if (isTesting) {
      if (game.getActivePlayer().getHandSize() >= 5) {
        cout << "Hand is full." << endl;
        return true;
      }
      game.drawCard();
      return true;
    } 
    cout << "'draw' is a testing mode specific command." << std::endl;
    return true;
  }
  if (command == "discard") {
    size_t i = 0;
    if (!(iss >> i) || iss >> command) {
      cout << "'discard' expects [int]. Type 'help' for more details." << endl;
      return true;
    }
    if (isTesting) {
      if (i < 1 || i > game.getActivePlayer().getHandSize()) {
        cout << "Card index is out of bounds." << endl;
        return true;
      }
      game.discard(i - 1);
      return true;
    }
    cout << "'discard' is a testing mode specific command." << std::endl;
    return true;
  }
  if (command == "attack") {
    size_t i = 0;
    size_t j = 0;
    if (!(iss >> i)) {
      cout << "'attack' expects [int] (optional:) [int]. Type 'help' for more details." << endl;
      return true;
    }
    if (!(iss >> j)) {
      iss.clear();
      if (iss >> command) {
        cout << "'attack' expects [int] (optional:) [int]. Type 'help' for more details." << endl;
        return true;
      }
      if (i < 1 || i > game.getActivePlayer().getActiveCardSize()) {
        cout << "Card index is out of bounds." << endl;
        return true;
      }
      if (game.getActivePlayer().getActiveCard(i - 1).getActions() > 0) {
        game.attackPlayer(i - 1, game.getOtherPlayer());
        return true;
      }
      cout << "This minion can not attack further for this term." << endl;
      return true;
    }
    if (iss >> command) {
      cout << "'attack' expects [int] (optional:) [int]. Type 'help' for more details." << endl;
      return true;
    }
    if (j < 1 || j > game.getOtherPlayer().getActiveCardSize()) {
      cout << "Card index is out of bounds." << endl;
      return true;
    }
    if (game.getActivePlayer().getActiveCard(i - 1).getActions() > 0) {
      game.attackMinion(i - 1, game.getOtherPlayer(), j - 1);
      return true;
    }
    // attack opposing minion
    cout << "This minion can not attack further for this term." << endl;
    return true;
  }
  if (command == "play") {
    size_t i = 0;
    int p = 0;
    size_t t = 0;
    if (!(iss >> i)) {
      cout << "'play' expects [int] (optional:) [int] [int]. Type 'help' for more details." << endl;
      return true;
    }
    if (!(iss >> p)) {
      iss.clear();
      if (iss >> command) {
        cout << "'play' expects [int] (optional:) [int] [int]. Type 'help' for more details." << endl;
        return true;
      }
      if (i < 1 || i > game.getActivePlayer().getHandSize()) {
        cout << "Card index is out of bounds." << endl;
        return true;
      }
      if (game.getActivePlayer().getHand().getCardCost(i - 1) > game.getActivePlayer().getMagic()) {
        cout << "Not enough magic." << endl;
        return true;
      }
      // Should checj now that it is spell or minion

      
      if (game.getActivePlayer().getActiveCardSize() >= 5) {
        cout << "Board is full." << endl;
        return true;
      }
      game.playCard(i - 1);
      return true;
    }
    if (!(iss >> t)) {
      cout << "'play' expects [int] (optional:) [int] [int]. Type 'help' for more details." << endl;
      return true;
    }
    iss.clear();
    if (iss >> command) {
      cout << "'play' expects [int] (optional:) [int] [int]. Type 'help' for more details." << endl;
      return true;
    }
    if (i < 1 || i > game.getActivePlayer().getHandSize()) {
      cout << "Card index is out of bounds." << endl;
      return true;
    }
    if (p != 1 && p != 2) {
      cout << "Please select a player." << endl;
      return true;
    }
    if (t < 1 || t > game.getActivePlayer().getActiveCardSize()) {
      cout << "Card index is out of bounds." << endl;
      return true;
    }
    if (p == 1) {
      game.playCard(i - 1, true, t - 1);
      return true;
    }
    // Play with target
    game.playCard(i - 1, false, t - 1);
    return true;
  }
  if (command == "use") {
    int i = 0;
    int p = 0;
    int t = 0;
    if (!(iss >> i)) {
      // Invalid
      return true;
    }
    if (!(iss >> p)) {
      // Play without target
      game.useCard(i - 1);
      return true;
    }
    if (!(iss >> t)) {
      // Invalid
      return true;
    }
    // Play with target
    if (p == 1) {
      game.useCard(i - 1, true, t - 1);
      return true;
    }
    // Play with target
    game.useCard(i - 1, false, t - 1);
    return true;
  }
  if (command == "inspect") {
    size_t i = 0;
    if (!(iss >> i) || iss >> command) {
      // Invalid
      cout << "'inspect' expects [int]. Type 'help' for more details." << endl;
      return true;
    }
    if (i < 1 || i > game.getActivePlayer().getActiveCardSize()) {
      cout << "Card index is out of bounds." << endl;
      return true;
    }
    text.inspect(game.getActivePlayer().getActiveCardPtr(i - 1));
    return true;
  }
  if (command == "hand") {
    if (iss >> command) {
      cout << "'hand' takes no subsequent arguments. Type 'help' for more details." << std::endl;
      return true;
    }
    text.displayHand();
    return true;
  }
  if (command == "board") {
    if (iss >> command) {
      cout << "'board' takes no subsequent arguments. Type 'help' for more details." << std::endl;
      return true;
    }
    text.displayBoard();
    return true;
  }
  // Invalid Command
  cout << "Invalid command. Type 'help' for a list of available commands." << endl;
  return true;
}
