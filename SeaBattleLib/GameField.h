#pragma once
#include "Ship.h"
#include "Position.h"
#include <vector>

class GameField {
public:
    GameField(int size = 10);

    int getSize() const;
    bool isInside(Position position) const;
    bool addShip(const Ship& ship);
    bool wasShot(Position position) const;
    int shoot(Position position);
    bool allShipsSunk() const;
    char getCell(Position position, bool showShips) const;

private:
    int size;
    std::vector<Ship> ships;
    std::vector<Position> shots;
};