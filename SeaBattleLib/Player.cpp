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

int Player::attack(Player& enemy, Position position) {
    return enemy.field.shoot(position);
}

bool Player::hasLost() const {
    return field.allShipsSunk();
}