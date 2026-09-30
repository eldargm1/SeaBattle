#pragma once
#include "Player.h"

class Game {
public:
    Game(const std::string& name1, const std::string& name2);
    void run();

private:
    Player player1;
    Player player2;
    int currentPlayer;
};
