#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include <iostream>
using std::string;

class Board
{
private:
	const int rows = 3;
	const int cols = 3;
	Tile** board;
	bool turn = false; // 'X' turn
public:
	Board();
	~Board();
	void mark(int row, int col);
	int hasWon();
	bool allFilled();
	bool getTurn();
	string getTurnString();
	Tile getTileValue(int row, int col);
	string toString();
	void emptyBoard();
};

#endif
