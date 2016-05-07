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

	void run();	
	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 800;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	Texture notRoomCell;
	Texture roomCell;
	Texture characterTex;
	Texture doorTexture;
	Texture earth;
	Texture background;
	Texture background2;
	Texture background3;



	bool running;

};

