#pragma once

#include "Character.h"
#include "Grid.h"

class MainCharacter: public Character
{ //The main version of character that user controllers
	//Should only be one instance of this class ??
public:
	MainCharacter();
	~MainCharacter();


	//Update function to be called on every frame update
	//Update now takes a direction then updates that charcter's x and y position accordingly
	void update(Grid grid, int windowWidth, int windowHeight);

	bool getCellState(int x, int y, int cellSize, std::vector<std::vector<std::shared_ptr<Cell>>> grid);

	void playerControlled(std::vector<std::vector<std::shared_ptr<Cell>>> grid, const Uint8* keyboardState, int windowWidth, int windowHeight);

	//States
	void playerControlled();
	void reactToFire();
	void reactToOxygen();
	void wanderAroundRoom();

};

