#include "Ship.h"

Ship::Ship(Position pos, int size, bool horizontal)
    : position(pos), size(size), horizontal(horizontal) {
}

Position Ship::getPosition() const {
    return position;
}

int Ship::getSize() const {
    return size;
}

bool Ship::isHorizontal() const {
    return horizontal;
}