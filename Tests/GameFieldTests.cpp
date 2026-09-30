#include "pch.h"
#include "GameField.h"

TEST(GameFieldTest, DefaultSize) {
    GameField f;
    EXPECT_EQ(f.getSize(), 10);
}

TEST(GameFieldTest, CustomSize) {
    GameField f(15);
    EXPECT_EQ(f.getSize(), 15);
}

TEST(GameFieldTest, ThrowsOnInvalidSize) {
    EXPECT_THROW(GameField(0), std::invalid_argument);
    EXPECT_THROW(GameField(-1), std::invalid_argument);
}

TEST(GameFieldTest, IsInside) {
    GameField f(5);

    EXPECT_TRUE(f.isInside(Position(0, 0)));
    EXPECT_TRUE(f.isInside(Position(4, 4)));
    EXPECT_FALSE(f.isInside(Position(5, 0)));
    EXPECT_FALSE(f.isInside(Position(0, 5)));
}

TEST(GameFieldTest, AddShip) {
    GameField f(5);
    Ship s(Position(0, 0), 2, true);

    EXPECT_TRUE(f.addShip(s));
}

TEST(GameFieldTest, AddShipOutOfBounds) {
    GameField f(5);
    Ship s(Position(4, 0), 3, true);

    EXPECT_FALSE(f.addShip(s));
}

TEST(GameFieldTest, AddOverlappingShips) {
    GameField f(5);

    EXPECT_TRUE(f.addShip(Ship(Position(0, 0), 2, true)));
    EXPECT_FALSE(f.addShip(Ship(Position(0, 0), 1, true)));
    EXPECT_FALSE(f.addShip(Ship(Position(1, 0), 1, true)));
}

TEST(GameFieldTest, ShootMiss) {
    GameField f(5);
    f.addShip(Ship(Position(0, 0), 1, true));

    EXPECT_EQ(f.shoot(Position(4, 4)), 0);
}

TEST(GameFieldTest, ShootHit) {
    GameField f(5);
    f.addShip(Ship(Position(0, 0), 2, true));

    EXPECT_EQ(f.shoot(Position(0, 0)), 1);
}

TEST(GameFieldTest, ShootSunk) {
    GameField f(5);
    f.addShip(Ship(Position(0, 0), 1, true));

    EXPECT_EQ(f.shoot(Position(0, 0)), 2);
    EXPECT_TRUE(f.allShipsSunk());
}

TEST(GameFieldTest, RepeatedShot) {
    GameField f(5);
    f.addShip(Ship(Position(0, 0), 1, true));

    EXPECT_EQ(f.shoot(Position(0, 0)), 2);
    EXPECT_EQ(f.shoot(Position(0, 0)), -1);
}

TEST(GameFieldTest, GetCellUnknown) {
    GameField f(5);
    EXPECT_EQ(f.getCell(Position(0, 0), false), '.');
}

TEST(GameFieldTest, GetCellMiss) {
    GameField f(5);
    f.shoot(Position(0, 0));
    EXPECT_EQ(f.getCell(Position(0, 0), false), 'o');
}

TEST(GameFieldTest, GetCellHit) {
    GameField f(5);
    f.addShip(Ship(Position(0, 0), 1, true));
    f.shoot(Position(0, 0));
    EXPECT_EQ(f.getCell(Position(0, 0), false), 'X');
}