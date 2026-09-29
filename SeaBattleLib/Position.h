#pragma once

class Position {
public:
    Position(int x = 0, int y = 0);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

private:
    int x;
    int y;
};
