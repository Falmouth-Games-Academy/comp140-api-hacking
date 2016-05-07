#include "stdafx.h"
#include "WanderingState.h"

WanderingState::WanderingState()
{
}


WanderingState::~WanderingState()
{
}

void WanderingState::update(Character& character, Grid grid, const Uint8* keyboardState)
{
	

	character.wanderAroundRoom();
	//TODO: Store previous location
	

	if (character.health == 0)
	{//When health = 0 the character enters the dead state
		character.state = std::make_shared<DeadState>();
		character.isAlive = false;
	}
	else if (character.getOxygenLevel(character.getX(), character.getY()) < 50)
	{//If the oxygen goes beneath a certain level the character slows down
		character.state = std::make_shared<LowOxygenState>();
		character.setSpeed(1); //Change to have a low oxygen speed
	}
	else if (keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_D])
	{//If the user presses WASD the character will move accordingly
		character.state = std::make_shared<PlayerControlledState>();
		character.moveCharacter(keyboardState);
	}
	else if (character.isCellOnFire(character.getX(), character.getY()))
	{//If a cell is on fire the character will move away
		character.state = std::make_shared<OnFire>();
		character.reactToFire();
	}


	
}
