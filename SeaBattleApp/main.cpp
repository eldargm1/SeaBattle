#include <iostream>
#include <exception>
#include "Game.h"

int main() {
    std::cout << "=== SeaBattle ===\n";
    std::cout << "Battleship game\n\n";

    try {
        Game game("Player 1", "Player 2");
        game.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}