#include "Tile.h"

Tile::Tile()
{
	empty = true;
	nought = false;
	cross = false;
}

bool Tile::isEmpty() { return empty; }

void Tile::setEmpty(bool empty) { this->empty = empty; }

bool Tile::isNought() { return nought; }

void Tile::setNought(bool nought) { this->nought = nought; }

bool Tile::isCross() { return cross; }

void Tile::setCross(bool cross) { this->cross = cross; }

char Tile::toString()
{
	if (isEmpty())
	{
		return '-';
	}
	else if (isNought())
	{
		return 'O';
	}
	return 'X';
}