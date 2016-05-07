#include "stdafx.h"
#include "MainCharacter.h"


MainCharacter::MainCharacter()
{
}


MainCharacter::~MainCharacter()
{
}

bool MainCharacter::getCellState(int x, int y, int cellSize, std::vector<std::vector<std::shared_ptr<Cell>>> grid)
{ //Currently checks to see if a cell is part of a room or not
	int xCell = x / cellSize;
	int yCell = y / cellSize;
	bool state = grid[xCell][yCell]->isRoom;
	return state;
}

void MainCharacter::playerControlled(std::vector<std::vector<std::shared_ptr<Cell>>> grid, const Uint8* keyboardState, int windowWidth, int windowHeight)
{
	bool roomState;
	// Checks keyboard state and deicdes whether the character can move in that direction
	if (keyboardState[SDL_SCANCODE_UP] || keyboardState[SDL_SCANCODE_W])
	{
		roomState = getCellState(getX(), getY() + getSpeed(), getSize(), grid);
		if (roomState == true && getY() + getSpeed() > 0) //Only lets character move if the next cell is a room and is on screen
		{
			setY(getY() - getSpeed());
			//updates chracter position depending on direction
		}
	}
	
	else if (keyboardState[SDL_SCANCODE_DOWN] || keyboardState[SDL_SCANCODE_S])
	{

		roomState = getCellState(getX(), getY() - getSpeed(), getSize(), grid);
		if (roomState == true && getY() - getSpeed() < windowHeight)
		{
			setY(getY() + getSpeed());
		}
	}
	else if (keyboardState[SDL_SCANCODE_LEFT] || keyboardState[SDL_SCANCODE_A])
	{
		roomState = getCellState(getX() - getSpeed(), getY(), getSize(), grid);
		if (roomState == true && getX() - getSpeed() > 0)
		{
			setX(getX() - getSpeed());
		}
	}
	else if (keyboardState[SDL_SCANCODE_RIGHT] || keyboardState[SDL_SCANCODE_D])
	{//Change from else if to if for diagonal movement
		roomState = getCellState(getX() + getSpeed(), getY(), getSize(), grid);
		if (roomState == true && getX() + getSpeed() < windowWidth)
		{
			setX(getX() + getSpeed());
		}
	}
	//else
		//state = std::make_shared<IdleState>();
}

void MainCharacter::reactToFire()
{
	health = health - 1;
}
void MainCharacter::reactToOxygen()
{
	setSpeed(getSpeed() / 2);
}
void MainCharacter::wanderAroundRoom()
{
	setX(getX());
}
