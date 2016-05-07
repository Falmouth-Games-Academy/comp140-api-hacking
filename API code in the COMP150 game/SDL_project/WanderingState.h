#pragma once
#include "CharacterState.h"
#include "PlayerControlledState.h"
class WanderingState :
	public CharacterState
{
public:
	WanderingState();
	~WanderingState();

	void update(Character& character, Grid grid, const Uint8* keyboardState);
};

