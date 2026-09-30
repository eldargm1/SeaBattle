#include "GameField.h"

GameField::GameField(int size) : size(size) {
}

int GameField::getSize() const {
    return size;
}