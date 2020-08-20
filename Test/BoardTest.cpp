#include "gtest/gtest.h"
#include "Board.h"

TEST(TestBoard, ToString)
{
	Board board;
	EXPECT_EQ("---\n---\n---\n", board.toString());
}

TEST(TestBoard, TestMark)
{
	Board board;
	board.mark(0, 0);
	board.mark(2, 2);
	board.mark(2, 1);
	EXPECT_EQ("X--\n---\n-XO\n", board.toString());
}

TEST(TestBoard, HasWon)
{
	Board board;
	board.mark(0, 0);
	board.mark(1, 0);
	board.mark(0, 1);
	board.mark(1, 1);
	board.mark(0, 2);
	EXPECT_EQ(1, board.hasWon());
}

TEST(TestBoard, AllFilled)
{
	Board board;
	board.mark(0, 0);
	board.mark(0, 1);
	board.mark(0, 2);
	board.mark(1,0);
	board.mark(1, 1);
	board.mark(1, 2);
	board.mark(2, 0);
	board.mark(2, 1);
	board.mark(2, 2);
	EXPECT_TRUE(board.allFilled());
}
