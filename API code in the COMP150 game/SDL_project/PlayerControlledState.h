#pragma once
#include "CharacterState.h"
#include "IdleState.h"
#include "DeadState.h"
#include "LowOxygenState.h"
#include"OnFire.h"

class PlayerControlledState :
	public CharacterState
{
	
public:
	PlayerControlledState();
	~PlayerControlledState();

	void update(Character& character, Grid grid, const Uint8* keyboardState);
};

