#include <string>
#include "input.h"
#include "game.h"

int main (int argc, char *argv[]) {
    bool ongoing = true; // false when we want to quit game
    
    // Pre-launch commands
    bool testing = false;
    bool graphics = false; // graphics display on/off
    if (argc > 1) {
        for (int i = 2; i < argc; i++) {
            if (argv[i] == "-init") {
                // do this later
            } else if (argv[i] == "-testing") {
                testing = true;
            } else if (argv[i] == "-deck1") {
                // do this later
            } else if (argv[i] == "-deck2") {
                // do this later
            } else if (argv[i] == "-graphics") {
                graphics = true;
            }
        }
    }

    Game game;

    Input input{game, testing}; // true is testing mode, false is normal

    while (ongoing) {
        ongoing = input.handleCommand(std::cin);
    }

    // since game and input are on the stack, the destructors will run themselves
}
