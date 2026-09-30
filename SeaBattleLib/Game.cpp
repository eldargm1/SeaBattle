#include "Game.h"
#include <iostream>
#include <stdexcept>

Game::Game(const std::string& name1, const std::string& name2)
    : player1(name1), player2(name2), currentPlayer(0) {
}

void Game::setupShips(Player& player) {
    GameField& field = player.getField();

    field.addShip(Ship(Position(0, 0), 2, true));
    field.addShip(Ship(Position(0, 2), 2, false));
    field.addShip(Ship(Position(2, 0), 3, true));
    field.addShip(Ship(Position(4, 4), 1, true));
}

void Game::printField(const GameField& field) const {
    int size = field.getSize();

    std::cout << "   ";
    for (int x = 0; x < size; ++x) {
        std::cout << x + 1 << " ";
    }
    std::cout << "\n";

    for (int y = 0; y < size; ++y) {
        std::cout << y + 1 << "  ";
        for (int x = 0; x < size; ++x) {
            std::cout << field.getCell(Position(x, y), false) << " ";
        }
        std::cout << "\n";
    }
}

void Game::printCurrentState() {
    int enemy = getEnemyIndex();
    Player& enemyPlayer = (enemy == 0) ? player1 : player2;

    std::cout << "\n=== Turn of " << getCurrentPlayerRef().getName() << " ===\n";
    std::cout << "Enemy field:\n";
    printField(enemyPlayer.getField());
}

int Game::getEnemyIndex() const {
    return 1 - currentPlayer;
}

Player& Game::getCurrentPlayerRef() {
    return (currentPlayer == 0) ? player1 : player2;
}

Player& Game::getEnemyPlayer() {
    return (currentPlayer == 0) ? player2 : player1;
}

Player& Game::getPlayer(int index) {
    if (index == 0) return player1;
    if (index == 1) return player2;
    throw std::out_of_range("Invalid player index");
}

int Game::getCurrentPlayer() const {
    return currentPlayer;
}

int Game::shoot(Position position) {
    if (isFinished()) {
        return -1;
    }

    int enemy = 1 - currentPlayer;
    Player& enemyPlayer = (enemy == 0) ? player1 : player2;

    int result = getCurrentPlayerRef().attack(enemyPlayer, position);

    if (result == 0) {
        currentPlayer = enemy;
    }

    return result;
}

bool Game::isFinished() const {
    return player1.hasLost() || player2.hasLost();
}

int Game::getWinner() const {
    if (player1.hasLost()) return 1;
    if (player2.hasLost()) return 0;
    return -1;
}

void Game::run() {
    std::cout << "=== SeaBattle ===\n\n";

    setupShips(player1);
    setupShips(player2);

    std::cout << "Player 1: " << player1.getName() << "\n";
    std::cout << "Player 2: " << player2.getName() << "\n";
    std::cout << "Ships placed. Game started!\n";

    while (!isFinished()) {
        printCurrentState();

        int x, y;
        std::cout << "Enter shot coordinates (x y): ";

        if (!(std::cin >> x >> y)) {
            std::cout << "Input error. Game over.\n";
            return;
        }

        Position shot(x - 1, y - 1);

        int result;
        try {
            result = getCurrentPlayerRef().attack(getEnemyPlayer(), shot);
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
            continue;
        }

        if (result == -1) {
            std::cout << "Invalid shot or already shot here.\n";
        }
        else if (result == 0) {
            std::cout << "Miss!\n";
            currentPlayer = getEnemyIndex();
        }
        else if (result == 1) {
            std::cout << "Hit!\n";
        }
        else {
            std::cout << "Ship sunk!\n";
        }
    }

    int winner = getWinner();
    std::cout << "\n=== Game over ===\n";
    std::cout << "Winner: ";
    if (winner == 0) {
        std::cout << player1.getName() << "\n";
    }
    else {
        std::cout << player2.getName() << "\n";
    }
}