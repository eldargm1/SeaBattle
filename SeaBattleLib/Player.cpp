#include "Player.h"

Player::Player(const std::string& name, int fieldSize)
    : name(name), field(fieldSize) {
}

std::string Player::getName() const {
    return name;
}

GameField& Player::getField() {
    return field;
}

const GameField& Player::getField() const {
    return field;
}