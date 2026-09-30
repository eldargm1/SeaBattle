#include "pch.h"
#include "Ship.h"

TEST(ShipTest, HorizontalShip) {
    Ship s(Position(0, 0), 3, true);
    EXPECT_EQ(s.getPositions().size(), 3u);
    EXPECT_TRUE(s.contains(Position(0, 0)));
    EXPECT_TRUE(s.contains(Position(1, 0)));
    EXPECT_TRUE(s.contains(Position(2, 0)));
    EXPECT_FALSE(s.contains(Position(0, 1)));
}

TEST(ShipTest, VerticalShip) {
    Ship s(Position(0, 0), 3, false);
    EXPECT_EQ(s.getPositions().size(), 3u);
    EXPECT_TRUE(s.contains(Position(0, 0)));
    EXPECT_TRUE(s.contains(Position(0, 1)));
    EXPECT_TRUE(s.contains(Position(0, 2)));
    EXPECT_FALSE(s.contains(Position(1, 0)));
}

TEST(ShipTest, ShootAndSink) {
    Ship s(Position(0, 0), 2, true);

    EXPECT_FALSE(s.isSunk());

    EXPECT_TRUE(s.shoot(Position(0, 0)));
    EXPECT_FALSE(s.isSunk());

    EXPECT_TRUE(s.shoot(Position(1, 0)));
    EXPECT_TRUE(s.isSunk());
}

TEST(ShipTest, RepeatedShoot) {
    Ship s(Position(0, 0), 2, true);

    EXPECT_TRUE(s.shoot(Position(0, 0)));
    EXPECT_FALSE(s.shoot(Position(0, 0)));
}

TEST(ShipTest, MissShoot) {
    Ship s(Position(0, 0), 1, true);

    EXPECT_FALSE(s.shoot(Position(5, 5)));
    EXPECT_FALSE(s.isSunk());
}