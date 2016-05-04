#include "stdafx.h"
#include "SpaceGame.h"
#include "InitialisationError.h"
#include "Cell.h"
#include "Grid.h"
#include "MainCharacter.h"
#include "ISSLocation.h"


SpaceGame::SpaceGame()
	: notRoomCell("Resources\\cell_test.png"), 
	roomCell("Resources\\cell_test2.png"),
	characterTex("Resources\\char.png"),
	earth("Resources\\earth.png"),
	bg("Resources\\bg.png")
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw InitialisationError("SDL_Init failed");
	}

	window = SDL_CreateWindow("COMP150 Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		throw InitialisationError("SDL_CreateWindow failed");
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		throw InitialisationError("SDL_CreateRenderer failed");
	}
}


SpaceGame::~SpaceGame()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool SpaceGame::getCellState(int x, int y, int cellSize, std::vector<std::vector<std::shared_ptr<Cell>>> grid)
{ //Currently checks to see if a cell is part of a room or not
	int xCell = x / cellSize;
	int yCell = y / cellSize;
	bool state = grid[xCell][yCell]->isRoom;
	return state;
}

void SpaceGame::run()
{
	Grid room;
	room.makeGrid(WINDOW_WIDTH, WINDOW_HEIGHT);
	Map mapLoader;
	mapLoader.LoadMap("Resources\\Map\\test_map.txt", room);
	MainCharacter characterOne;

	ISSLocation location;
	location.requestJSONValueAsync().wait(); //Runs once in the set up to get a previous update time
	location.update(); //Sets x and y position of background

	running = true;
	while (running)
	{
		// Handle events
		SDL_Event ev;
		if (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			default:
				break;
			}
		}//End pollevent if

		//checks keyboard state then updates character
		const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
		bool roomState;
		// Checks keyboard state and deicdes whether the character can move in that direction
		if (keyboardState[SDL_SCANCODE_UP] || keyboardState[SDL_SCANCODE_W])
		{
			roomState = getCellState(characterOne.getX(), characterOne.getY() + characterOne.getSpeed(), characterOne.getSize(), room.grid);
			if (roomState == true && characterOne.getY() + characterOne.getSpeed() > 0) //Only lets character move if the next cell is a room and is on screen
			{
				characterOne.update("up");
				//updates chracter position depending on direction
			}
		}
			
		else if (keyboardState[SDL_SCANCODE_DOWN] || keyboardState[SDL_SCANCODE_S])
		{

			roomState = getCellState(characterOne.getX(), characterOne.getY() - characterOne.getSpeed(), characterOne.getSize(), room.grid);
			if (roomState == true && characterOne.getY() - characterOne.getSpeed() < WINDOW_HEIGHT)
			{
				characterOne.update("down");
			}
		}
		else if (keyboardState[SDL_SCANCODE_LEFT] || keyboardState[SDL_SCANCODE_A])
		{
			roomState = getCellState(characterOne.getX() - characterOne.getSpeed(), characterOne.getY(), characterOne.getSize(), room.grid);
			if (roomState == true && characterOne.getX() - characterOne.getSpeed() > 0)
			{
				characterOne.update("left");
			}
		}
		else if (keyboardState[SDL_SCANCODE_RIGHT] || keyboardState[SDL_SCANCODE_D])  
		{//Change from else if to if for diagonal movement
			roomState = getCellState(characterOne.getX() + characterOne.getSpeed(), characterOne.getY(), characterOne.getSize(), room.grid);
			if (roomState == true && characterOne.getX() + characterOne.getSpeed() < WINDOW_WIDTH)
			{
				characterOne.update("right");
			}
		}
		
		location.update(); //Updates ISS location and timestamp

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		int cellSize = room.getCellSize();
		
		//TODO: add function that chooses position based on ISS
		bg.render(renderer, location.backgroundXPos, location.backgroundYPos , 2000, 2000); //Renders background
		earth.render(renderer, 400, 400, 800, 800); //Renders earth

		for (int x = 0; x < room.grid.size(); x++)
		{
			for (int y = 0; y < room.grid[x].size(); y++)
			{
				int xPos = x * cellSize + cellSize / 2;
				int yPos = y * cellSize + cellSize / 2;
					
				//Renders cell based on state
				if (room.grid[x][y]->isRoom) // Detects if the cell is a room
				{
					roomCell.render(renderer, xPos, yPos, cellSize, cellSize);
				}
				// If a cell isn't part of a room it isn't rendered
			} //End for Y loop
		
			//cellSprite.render(renderer, room.grid[i].getX() * cellSize + cellSize / 2, room.grid[i].getY() * cellSize + cellSize / 2, cellSize, cellSize);	
			
		}//End for X loop
		
		characterTex.render(renderer, characterOne.getX(), characterOne.getY(), characterOne.getSize(), characterOne.getSize());
		
		SDL_RenderPresent(renderer);
	}//End while running

}
