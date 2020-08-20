#include "Board.h"

Board::Board()
{
    board = new Tile * [rows];
    for (int i = 0; i < cols; i++) {
        board[i] = new Tile[cols];
    }
}

void Board::mark(int row, int col)
{
    if (board[row][col].isNought() || board[row][col].isCross()) {
        return;
    }
    else if (!turn) {
        board[row][col].setEmpty(false);
        board[row][col].setCross(true);
        turn = true;
    }
    else {
        board[row][col].setEmpty(false);
        board[row][col].setNought(true);
        turn = false;
    }
}

int Board::hasWon()
{
    // row wins
    if (board[0][0].isNought() && board[0][1].isNought() && board[0][2].isNought() ||
        board[1][0].isNought() && board[1][1].isNought() && board[1][2].isNought() ||
        board[2][0].isNought() && board[2][1].isNought() && board[2][2].isNought() ||
        board[0][0].isCross() && board[0][1].isCross() && board[0][2].isCross() ||
        board[1][0].isCross() && board[1][1].isCross() && board[1][2].isCross() ||
        board[2][0].isCross() && board[2][1].isCross() && board[2][2].isCross()) {
        return 1;
    }
    // col wins
    else if (board[0][0].isNought() && board[1][0].isNought() && board[2][0].isNought() ||
        board[0][1].isNought() && board[1][1].isNought() && board[2][1].isNought() ||
        board[0][2].isNought() && board[1][2].isNought() && board[2][2].isNought() ||
        board[0][0].isCross() && board[1][0].isCross() && board[2][0].isCross() ||
        board[0][1].isCross() && board[1][1].isCross() && board[2][1].isCross() ||
        board[0][2].isCross() && board[1][2].isCross() && board[2][2].isCross()) {
        return 1;
    }
    // diagonal wins
    else if (board[0][0].isNought() && board[1][1].isNought() && board[2][2].isNought() ||
        board[0][2].isNought() && board[1][1].isNought() && board[2][0].isNought() ||
        board[0][0].isCross() && board[1][1].isCross() && board[2][2].isCross() ||
        board[0][2].isCross() && board[1][1].isCross() && board[2][0].isCross()) {
        return 1;
    }
    // tie
    else if (allFilled()) {
        return 2;
    }
    return 0;
}

/* Helper method for draw */
bool Board::allFilled()
{
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!board[i][j].isEmpty()) {
                count++;
            }
        }
    }
    if (count == 9) {
        return true;
    }
    return false;
}

bool Board::getTurn() { return turn; }

string Board::getTurnString()
{
    if (turn) {
        return "X";
    }
    return "O";
}

Tile Board::getTileValue(int row, int col) { return board[row][col]; }

string Board::toString()
{
    string s = "";
    int line = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            s += board[i][j].toString();
            line++;
            if (line == 3) {
                s += "\n";
                line = 0;
            }
        }
    }
    return s;
}

void Board::emptyBoard()
{
    turn = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j].isCross() || board[i][j].isNought()) {
                board[i][j].setEmpty(true);
                board[i][j].setCross(false);
                board[i][j].setNought(false);
            }
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < rows; ++i) {
        delete[] board[i];
    }
    delete[] board;
}