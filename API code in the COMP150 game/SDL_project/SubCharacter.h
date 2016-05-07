#pragma once
#include "Character.h"
class SubCharacter :
	public Character
{
public:
	//Another version of characters that isn't controlled by the player....
	SubCharacter();
	~SubCharacter();

	//TODO:
	// -Pointer to instance of a MainCharacter 
	// -Two states - reacts to MainCharacters state
	// -Uses its own state for fire/dead/low oxygen
	// -Follows/Moves towards MainCharacter
	// - Has to stay a certain distance away from MainCharacter
	// - Stop following if MainCharacter is on fire/low o2 etc.

	void moveCharacter(const Uint8* keyboardState);  //Overwrite Characters moveCharacter to make subCharacter follow mainCharacter
};

