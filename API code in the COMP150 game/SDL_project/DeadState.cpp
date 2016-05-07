#include "stdafx.h"
#include "DeadState.h"


DeadState::DeadState()
{
}


DeadState::~DeadState()
{
}

void DeadState::update(Character& character, Grid grid, const Uint8* keyboardState)
{
	//If the character runs out of health they enter the dead state
	//The character can't exit this state
	//TODO: Will check to see if other characters are still alive

	character.isAlive = false;
}
