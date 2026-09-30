#include "pch.h"
#include "Ship.h"

TEST(ShipTest, Constructor) {
    Ship s(Position(1, 2), 3, true);
    EXPECT_EQ(s.getSize(), 3);
    EXPECT_TRUE(s.isHorizontal());
}

TEST(ShipTest, Position) {
    Ship s(Position(5, 7), 2, false);
    EXPECT_EQ(s.getPosition().getX(), 5);
    EXPECT_EQ(s.getPosition().getY(), 7);
}

TEST(ShipTest, VerticalShip) {
    Ship s(Position(0, 0), 4, false);
    EXPECT_FALSE(s.isHorizontal());
}

TEST(ShipTest, SizeOne) {
    Ship s(Position(0, 0), 1, true);
    EXPECT_EQ(s.getSize(), 1);
}