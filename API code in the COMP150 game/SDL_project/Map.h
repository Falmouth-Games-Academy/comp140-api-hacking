#pragma once
#include "grid.h"
class Map
{
public:
	Map();
	~Map();
	void LoadMap(std::string filename, Grid room);
	/*
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	*/
	

private:
	//For a 800px X 800px window size there are 16 cols X 16 rows
	/*
	Map* map;
	int width;
	int height;
	*/
	//determines what type of cell it is from the file.
	//int Cell_Value;
};


