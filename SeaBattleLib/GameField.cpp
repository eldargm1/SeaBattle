#include "GameField.h"
#include <stdexcept>

GameField::GameField(int size) : size(size) {
    if (size <= 0) {
        throw std::invalid_argument("Field size must be positive");
    }
}

int GameField::getSize() const {
    return size;
}

bool GameField::isInside(Position position) const {
    return position.getX() >= 0 && position.getX() < size &&
        position.getY() >= 0 && position.getY() < size;
}

bool GameField::addShip(const Ship& ship) {
    for (const Position& cell : ship.getPositions()) {
        if (!isInside(cell)) {
            return false;
        }

        for (const Ship& existingShip : ships) {
            for (const Position& existingCell : existingShip.getPositions()) {
                int dx = cell.getX() - existingCell.getX();
                int dy = cell.getY() - existingCell.getY();

                if (dx >= -1 && dx <= 1 && dy >= -1 && dy <= 1) {
                    return false;
                }
            }
        }
    }

    if (!shots.empty()) {
        return false;
    }

    ships.push_back(ship);
    return true;
}

bool GameField::wasShot(Position position) const {
    for (const Position& shot : shots) {
        if (shot == position) {
            return true;
        }
    }
    return false;
}

int GameField::shoot(Position position) {
    if (!isInside(position) || wasShot(position)) {
        return -1;
    }

    shots.push_back(position);

    for (Ship& ship : ships) {
        if (ship.shoot(position)) {
            if (ship.isSunk()) {
                return 2;
            }
            return 1;
        }
    }

    return 0;
}

bool GameField::allShipsSunk() const {
    if (ships.empty()) {
        return false;
    }

    for (const Ship& ship : ships) {
        if (!ship.isSunk()) {
            return false;
        }
    }
    return true;
}

char GameField::getCell(Position position, bool showShips) const {
    if (!isInside(position)) {
        return '?';
    }

    bool hasShip = false;
    for (const Ship& ship : ships) {
        if (ship.contains(position)) {
            hasShip = true;
            break;
        }
    }

    if (wasShot(position)) {
        return hasShip ? 'X' : 'o';
    }

    if (showShips && hasShip) {
        return 'S';
    }

    return '.';
}