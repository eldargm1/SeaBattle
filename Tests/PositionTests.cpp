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

TEST(PositionTest, NegativeValues) {
    Position p(-3, -5);
    EXPECT_EQ(p.getX(), -3);
    EXPECT_EQ(p.getY(), -5);
}