#include "pch.h"
#include "Game.h"

TEST(GameTest, Constructor) {
    Game g("Alice", "Bob");
    EXPECT_TRUE(true);
}

TEST(GameTest, RunDoesNotThrow) {
    Game g("Alice", "Bob");
    EXPECT_NO_THROW(g.run());
}