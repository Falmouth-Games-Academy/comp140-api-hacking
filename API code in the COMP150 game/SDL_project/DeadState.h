#pragma once
#include"CharacterState.h"
#include"Character.h"

class DeadState: public CharacterState
{
public:
	DeadState();
	~DeadState();

	void update(Character& character, Grid grid, const Uint8* keyboardState);
};

