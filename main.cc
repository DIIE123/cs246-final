#include <string>
#include <fstream>
#include <iostream>
#include "input.h"
#include "game.h"

int main (int argc, char *argv[]) {
    bool ongoing = true; // false when we want to quit game

    // Defaults and Files
    std::string name1 = "player1";
    std::string name2 = "player2";
    std::string deck1 = "default.deck";
    std::string deck2 = "default.deck";
    
    // Pre-launch commands
    bool testing = false;
    bool graphics = false; // graphics display on/off
    for (int i = 1; i < argc; i++) {
        std::string command = argv[i];
        if (command == "-init") {
            // add init later
            i++;
        } else if (command == "-testing") {
            testing = true;
        } else if (command == "-deck1") {
            deck1 = argv[i + 1];
            i++;
        } else if (command == "-deck2") {
            deck2 = argv[i + 1];
            i++;
        } else if (command == "-graphics") {
            graphics = true;
        }
    }

    Game game{name1, name2, deck1, deck2};

    Text text{game};

    Input input{game, text, testing}; // true is testing mode, false is normal

    while (ongoing) {
        ongoing = input.handleCommand(std::cin);
    }
    
    // since game and input are on the stack, the destructors will run themselves
}
