#pragma once

#include "Texture.h"

class Cell
{
public:
	Cell();
	~Cell();
	
	bool isRoom = true;  //Whether the cell is part of a room or not
	bool isDoor = false;
	bool onFire = false;
	int oxygenLevel = 100;


	int getX() { return x; }
	int getY() { return y; }
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }

private:

	Texture* sprite;
	int x, y;

};