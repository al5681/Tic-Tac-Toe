#include "pch.h"
#include "Tile.h"

struct TileTest : testing::Test
{
	Tile* tile;

	TileTest()
	{
		tile = new Tile;
	}
	~TileTest()
	{
		delete tile;
	}
};

/* Test the empty getters and setters work*/
TEST_F(TileTest, IsEmptyTest) {
	EXPECT_TRUE(tile->isEmpty());
	tile->setEmpty(false);
	EXPECT_FALSE(tile->isEmpty());
}

/* Test the nought getters and setters work*/
TEST_F(TileTest, IsNoughtTest) {
	EXPECT_FALSE(tile->isNought());
	tile->setNought(true);
	EXPECT_TRUE(tile->isNought());
}

/* Test the cross getters and setters work*/
TEST_F(TileTest, IsCrossTest) {
	EXPECT_FALSE(tile->isCross());
	tile->setCross(true);
	EXPECT_TRUE(tile->isCross());
}
