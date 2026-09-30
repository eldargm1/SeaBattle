#pragma once
#include "GameField.h"
#include <string>

class Player {
public:
    Player(const std::string& name, int fieldSize = 10);
    std::string getName() const;
    GameField& getField();
    const GameField& getField() const;

    int attack(Player& enemy, Position position);
    bool hasLost() const;

private:
    std::string name;
    GameField field;
};