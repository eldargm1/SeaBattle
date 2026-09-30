#pragma once
#include "GameField.h"
#include <string>

class Player {
public:
    Player(const std::string& name, int fieldSize = 10);
    std::string getName() const;
    GameField& getField();
    const GameField& getField() const;

private:
    std::string name;
    GameField field;
};