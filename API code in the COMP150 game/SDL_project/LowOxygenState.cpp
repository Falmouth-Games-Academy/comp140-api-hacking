#include "stdafx.h"
#include "LowOxygenState.h"


LowOxygenState::LowOxygenState()
{
}


LowOxygenState::~LowOxygenState()
{
}

void LowOxygenState::update(Character& character, Grid grid)
{
	character.setSpeed(1);  // TODO: Change to a variable and use framerate
	if (character.getOxygenLevel(character.getX(), character.getY()) > 50)
	{
		character.state = std::make_shared<IdleState>();
		character.setSpeed(2);
	}
}