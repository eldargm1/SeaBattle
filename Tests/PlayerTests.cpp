#include "pch.h"
#include "Player.h"

TEST(PlayerTest, Constructor) {
    Player p("Alice");
    EXPECT_EQ(p.getName(), "Alice");
    EXPECT_EQ(p.getField().getSize(), 10);
}

TEST(PlayerTest, CustomFieldSize) {
    Player p("Bob", 5);
    EXPECT_EQ(p.getField().getSize(), 5);
}

TEST(PlayerTest, AttackHits) {
    Player first("Alice");
    Player second("Bob");

    second.getField().addShip(Ship(Position(0, 0), 1, true));

    EXPECT_EQ(first.attack(second, Position(0, 0)), 2);
}

TEST(PlayerTest, AttackMisses) {
    Player first("Alice");
    Player second("Bob");

    second.getField().addShip(Ship(Position(0, 0), 1, true));

    EXPECT_EQ(first.attack(second, Position(4, 4)), 0);
}

TEST(PlayerTest, HasLostInitiallyFalse) {
    Player p("Alice");
    p.getField().addShip(Ship(Position(0, 0), 1, true));

    EXPECT_FALSE(p.hasLost());
}

TEST(PlayerTest, HasLostAfterAllSunk) {
    Player p("Alice");
    Player enemy("Bob");

    p.getField().addShip(Ship(Position(0, 0), 1, true));
    enemy.attack(p, Position(0, 0));

    EXPECT_TRUE(p.hasLost());
}