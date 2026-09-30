#pragma once
#include "Player.h"
#include <string>

class Game {
public:
    Game(const std::string& name1, const std::string& name2);
    void run();

    bool isFinished() const;
    int getWinner() const;

    Player& getPlayer(int index);
    int getCurrentPlayer() const;
    int shoot(Position position);

private:
    Player player1;
    Player player2;
    int currentPlayer;

    void setupShips(Player& player);
    void printField(const GameField& field) const;
    void printCurrentState();
    int getEnemyIndex() const;
    Player& getCurrentPlayerRef();
    Player& getEnemyPlayer();
};