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

TEST(PlayerTest, NameIsStored) {
    Player p("Charlie", 8);
    EXPECT_EQ(p.getName(), "Charlie");
}

TEST(PlayerTest, GetFieldMutable) {
    Player p("Dave");
    GameField& f = p.getField();
    EXPECT_EQ(f.getSize(), 10);
}