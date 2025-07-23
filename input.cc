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
      game.drawCard();
      return true;
    } 
    cout << "'draw' is a testing mode specifc command." << std::endl;
    return true;
  }
  if (command == "discard") {
    size_t i = 0;
    if (!(iss >> i) || iss >> command) {
      cout << "'discard' expects [int]. Type 'help' for more details." << endl;
      return true;
    }
    if (isTesting) {
      game.discard(i);
      return true;
    }
    cout << "'discard' is a testing mode specifc command." << std::endl;
    return true;
  }
  if (command == "attack") {
    size_t i = 0;
    size_t j = 0;
    if (!(iss >> i)) {
      cout << "'attack' expects [int] (optional:) [int]. Type 'help' for more details." << endl;
      return true;
    }
    // Checks bound
    // if (i >= game.current.getSize());
    if (!(iss >> j)) {
      
      // attack opposing player
      return true;
    }
    // Checks bound
    // if (j >= game.current.getSize());
    // attack jth minion
    return true;
  }
  // Remember to check bounds!
  if (command == "play") {
    size_t i = 0;
    size_t p = 0;
    size_t t = 0;
    if (!(iss >> i)) {
      // Invalid
      return true;
    }
    if (!(iss >> p)) {
      // Play without target
    }
    if (!(iss >> t)) {
      // Invalid
      return true;
    }
    // Play with target
    return true;
  }
  if (command == "use") {
    size_t i = 0;
    size_t p = 0;
    size_t t = 0;
    if (!(iss >> i)) {
      // Invalid
      return true;
    }
    if (!(iss >> p)) {
      // Play without target
      return true;
    }
    if (!(iss >> t)) {
      // Invalid
      return true;
    }
    // Play with target
    return true;
  }
  if (command == "inspect") {
    size_t i = 0;
    if (!(iss >> i) || iss >> command) {
      // Invalid
      cout << "'inspect' expects [int]. Type 'help' for more details." << endl;
      return true;
    }
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
