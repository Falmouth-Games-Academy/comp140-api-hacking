#pragma once
class Oxygen
{
public:
	Oxygen();
	~Oxygen();

	int Get_Oxygen_Level() { return Oxygen_Level; }
	void spawnOxygen();

private:
	int Oxygen_Level = 0;
	
};