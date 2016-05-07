#include "stdafx.h"
#include "PlayerControlledState.h"


PlayerControlledState::PlayerControlledState()
{
}


PlayerControlledState::~PlayerControlledState()
{
}

void PlayerControlledState::update(Character& character, Grid grid, const Uint8* keyboardState)
{
	character.moveCharacter(keyboardState);

	if (character.health == 0)
	{
		character.state = std::make_shared<DeadState>();
		character.isAlive = false;
	}
	else if (!(keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_D]))
	{
		character.state = std::make_shared<IdleState>();
		character.state->timer = 0;
	}
	else if (character.getOxygenLevel(character.getX(), character.getY()) < 50)
	{
		character.state = std::make_shared<LowOxygenState>();
		character.setSpeed(1);
	}
	else if (character.isCellOnFire(character.getX(), character.getY()))
	{
	character.state = std::make_shared<OnFire>();
	character.reactToFire();
	}
}
