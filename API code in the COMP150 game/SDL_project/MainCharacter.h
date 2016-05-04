#pragma once

#include "Character.h"

class MainCharacter: public Character
{ //The main version of character that user controllers
public:
	MainCharacter();
	~MainCharacter();


	//Update function to be called on every frame update
	//Update now takes a direction then updates that charcter's x and y position accordingly
	void update(std::string direction);


};

