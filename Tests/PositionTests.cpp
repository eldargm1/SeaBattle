#include "pch.h"
#include "Position.h"

TEST(PositionTest, DefaultConstructor) {
    Position p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
}

TEST(PositionTest, ConstructorWithValues) {
    Position p(3, 5);
    EXPECT_EQ(p.getX(), 3);
    EXPECT_EQ(p.getY(), 5);
}

TEST(PositionTest, SetX) {
    Position p(1, 1);
    p.setX(7);
    EXPECT_EQ(p.getX(), 7);
    EXPECT_EQ(p.getY(), 1);
}

TEST(PositionTest, SetY) {
    Position p(1, 1);
    p.setY(9);
    EXPECT_EQ(p.getX(), 1);
    EXPECT_EQ(p.getY(), 9);
}

TEST(PositionTest, Equality) {
    EXPECT_TRUE(Position(1, 2) == Position(1, 2));
    EXPECT_FALSE(Position(1, 2) == Position(2, 1));
    EXPECT_FALSE(Position(1, 2) == Position(1, 3));
}

TEST(PositionTest, NegativeValuesThrow) {
    EXPECT_THROW(Position(-3, -5), std::invalid_argument);
    EXPECT_THROW(Position(-3, 0), std::invalid_argument);
    EXPECT_THROW(Position(0, -5), std::invalid_argument);
}

TEST(PositionTest, NegativeSetThrows) {
    Position p(1, 1);
    EXPECT_THROW(p.setX(-1), std::invalid_argument);
    EXPECT_THROW(p.setY(-1), std::invalid_argument);
}