#include "stdafx.h"
#include "Grid.h"


//Populates a 2 dimentional vector with pointers to cells
void Grid::makeGrid(int Window_Width, int Window_Height)
{
	//Calculate the number of cells on each axis
	int XAxis_Max = Window_Width / cellSize;
	int YAxis_Max = Window_Height / cellSize;

	for (int x = 0; x < XAxis_Max; x++)
	{
		//Pushes back a column into the row
		std::vector<std::shared_ptr<Cell>> column;
		grid.push_back(column);
		for (int y = 0; y < YAxis_Max; y++)
		{
			//populates the column with pointers to cells
			Cell cell;
			cell.setX(x);
			cell.setY(y);
			auto sharedCell = std::make_shared<Cell> (cell);
			grid[x].push_back(sharedCell);
		}
	}
}

Grid::Grid()
{
}


Grid::~Grid()
{
}
