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

TEST(GameFieldTest, SmallSize) {
    GameField f(5);
    EXPECT_EQ(f.getSize(), 5);
}