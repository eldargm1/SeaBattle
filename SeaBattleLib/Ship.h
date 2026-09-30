#pragma once
#include "Position.h"
#include <vector>

class Ship {
public:
    Ship(Position start, int size, bool horizontal);

    const std::vector<Position>& getPositions() const;
    bool contains(Position position) const;
    bool shoot(Position position);
    bool isSunk() const;

private:
    std::vector<Position> positions;
    std::vector<bool> hits;
};