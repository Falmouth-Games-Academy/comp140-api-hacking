#pragma once
#include"Character.h"
#include"Grid.h"


class CharacterState
{
public:
	CharacterState();
	~CharacterState();

	double timer = 0; //used when entering or using IdleState
	int END_IDLE_TIME = 2;//How long the character will still idle before switching to the wandering state

	virtual void update(Character& character, Grid grid, const Uint8* keyboardState);
    //Will check on each frame what state the character should be in
	//And will call the corresponding function from Character

};