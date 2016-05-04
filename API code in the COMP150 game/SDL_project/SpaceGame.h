#pragma once

#include "Texture.h"
#include "Grid.h"
#include "Map.h"
#include "GameConfiguration.h"


class SpaceGame
{
public:
	SpaceGame();
	~SpaceGame();

	bool getCellState(int x, int y, int cellSize, std::vector<std::vector<std::shared_ptr<Cell>>> grid);
	void updateBackground();
	void run();

	
	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 800;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Texture notRoomCell;
	Texture roomCell;
	Texture characterTex;
	Texture earth;
	Texture bg;

	bool running;

};

