#include "Position.h"
#include <stdexcept>

Position::Position(int x, int y) : x(x), y(y) {
    if (x < 0) {
        throw std::invalid_argument("X must be non-negative");
    }
    if (y < 0) {
        throw std::invalid_argument("Y must be non-negative");
    }
}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

void Position::setX(int x) {
    if (x < 0) {
        throw std::invalid_argument("X must be non-negative");
    }
    this->x = x;
}

void Position::setY(int y) {
    if (y < 0) {
        throw std::invalid_argument("Y must be non-negative");
    }
    this->y = y;
}

bool Position::operator==(const Position& other) const {
    return x == other.x && y == other.y;
}