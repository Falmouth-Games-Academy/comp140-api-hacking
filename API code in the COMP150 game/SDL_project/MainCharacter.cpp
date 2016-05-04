#include "stdafx.h"
#include "MainCharacter.h"


MainCharacter::MainCharacter()
{
}


MainCharacter::~MainCharacter()
{
}


void MainCharacter::update(std::string direction)
{ //Updates the the characters postion based on the keyboard key pressed and the characters current speed
	if (direction == "up")
		setY(getY() - getSpeed());
	else if (direction == "down")
		setY(getY() + getSpeed());
	else if (direction == "left")
		setX(getX() - getSpeed());
	else if (direction == "right")
		setX(getX() + getSpeed());
}
