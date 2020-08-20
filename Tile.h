#ifndef TILE_H
#define TILE_H

class Tile
{
private:
	bool empty;
	bool nought;
	bool cross;
public:
	Tile();
	bool isEmpty();
	void setEmpty(bool empty);
	bool isNought();
	void setNought(bool nought);
	bool isCross();
	void setCross(bool cross);
	char toString();
};

#endif
