#pragma once
#include "CharacterState.h"
#include "DeadState.h"
#include "IdleState.h"

class LowOxygenState :
	public CharacterState
{
public:
	LowOxygenState();
	~LowOxygenState();

	void update(Character& character, Grid grid);
};

