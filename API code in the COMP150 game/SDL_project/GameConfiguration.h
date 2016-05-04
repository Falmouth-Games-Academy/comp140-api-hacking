#pragma once
class GameConfiguration
{
public:
	static GameConfiguration& getInstance() { return instance; };
	~GameConfiguration();

	int getWidth() { return WINDOW_WIDTH; }
	int getHeight() { return WINDOW_HEIGHT; }
	int getFramRate() { return FRAME_RATE; }


private:
	GameConfiguration();
	static GameConfiguration instance;

	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 800;
	static const int FRAME_RATE;
	// static const int cellsize;  //link cellsize & width/height??
};

