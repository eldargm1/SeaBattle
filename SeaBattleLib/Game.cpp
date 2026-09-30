#include "Game.h"
#include <iostream>

Game::Game(const std::string& name1, const std::string& name2)
    : player1(name1), player2(name2), currentPlayer(1) {
}

void Game::run() {
    std::cout << "=== SeaBattle ===\n";
    std::cout << "Player 1: " << player1.getName() << "\n";
    std::cout << "Player 2: " << player2.getName() << "\n";
    std::cout << "Game started!\n";
}