#include "pch.h"
#include "Game.h"

TEST(GameTest, Constructor) {
    Game g("Alice", "Bob");
    EXPECT_EQ(g.getCurrentPlayer(), 0);
    EXPECT_FALSE(g.isFinished());
    EXPECT_EQ(g.getWinner(), -1);
}

TEST(GameTest, ChangeTurnAfterMiss) {
    Game g("Alice", "Bob");

    g.getPlayer(0).getField().addShip(Ship(Position(0, 0), 1, true));
    g.getPlayer(1).getField().addShip(Ship(Position(2, 2), 1, true));

    EXPECT_EQ(g.getCurrentPlayer(), 0);
    EXPECT_EQ(g.shoot(Position(4, 4)), 0);
    EXPECT_EQ(g.getCurrentPlayer(), 1);
}

TEST(GameTest, SameTurnAfterHit) {
    Game g("Alice", "Bob");

    g.getPlayer(0).getField().addShip(Ship(Position(0, 0), 2, true));
    g.getPlayer(1).getField().addShip(Ship(Position(2, 2), 1, true));

    EXPECT_EQ(g.getCurrentPlayer(), 0);
    EXPECT_EQ(g.shoot(Position(2, 2)), 2);
    EXPECT_TRUE(g.isFinished());
}

TEST(GameTest, Victory) {
    Game g("Alice", "Bob");

    g.getPlayer(0).getField().addShip(Ship(Position(0, 0), 1, true));
    g.getPlayer(1).getField().addShip(Ship(Position(2, 2), 1, true));

    EXPECT_FALSE(g.isFinished());

    g.shoot(Position(2, 2));

    EXPECT_TRUE(g.isFinished());
    EXPECT_EQ(g.getWinner(), 0);
}