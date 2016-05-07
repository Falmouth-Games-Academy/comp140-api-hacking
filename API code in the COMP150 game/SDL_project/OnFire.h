#pragma once
#include "CharacterState.h"
#include "DeadState.h"
#include "IdleState.h"
#include "OnFire.h"
#include "PlayerControlledState.h"
class OnFire :
	public CharacterState
{
public:
	//If the character is in on or one cell away from fire they'll run away
	OnFire();
	~OnFire();

	void update(Character& character, Grid grid, const Uint8* keyboardState);
};

