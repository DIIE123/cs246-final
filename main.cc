#include <string>
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
    if (argc > 1) {
        for (int i = 2; i < argc; i++) {
            if (argv[i] == "-init") {
                // add init later
                i++;
            } else if (argv[i] == "-testing") {
                testing = true;
            } else if (argv[i] == "-deck1") {
                i++;
                deck1 = argv[i];
            } else if (argv[i] == "-deck2") {
                i++;
                deck2 = argv[i];
            } else if (argv[i] == "-graphics") {
                graphics = true;
            }
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
