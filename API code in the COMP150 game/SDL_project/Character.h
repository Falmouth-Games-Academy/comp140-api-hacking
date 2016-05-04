#pragma once
class Character
{//Abstract character class that the other types of character will inherit from
public:
	Character();
	~Character();

	
	//Getter methods
	int getX() { return x; }
	int getY() { return y; }
	int getSize() { return size; }
	int getSpeed() { return moveSpeed; }

	//Setter methods
	int setX(int newX) { return x = newX; }
	int setY(int newY) { return y = newY; }
	int setSpeed(int newSpeed) { return moveSpeed = newSpeed; }

	//Update function to be called on every frame update
	void update();



private:
	int x = 10, y = 10; //Characters intial start X and Y position
	int size = 100;  //The size of the character sprite when rendered 
	int moveSpeed = 2; //The speed that the character intially moves at
};

