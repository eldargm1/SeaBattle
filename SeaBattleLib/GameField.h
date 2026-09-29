#pragma once
#include "Ship.h"
#include <vector>

class GameField {
public:
    GameField(int size = 10);
    int getSize() const;

private:
    int size;
    std::vector<Ship> ships;
};
