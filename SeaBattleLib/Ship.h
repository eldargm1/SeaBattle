#pragma once
#include "Position.h"

class Ship {
public:
    Ship(Position pos, int size, bool horizontal);
    Position getPosition() const;
    int getSize() const;
    bool isHorizontal() const;

private:
    Position position;
    int size;
    bool horizontal;
};
