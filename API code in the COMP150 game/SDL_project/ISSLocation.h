#pragma once
class ISSLocation
{
public:
	ISSLocation();
	~ISSLocation();


	int updateTime = 0, previousUpdateTime = 0, windowWidth = 800, windowHeight = 800;
	double longitude, latitude;
	double backgroundXPos = 400, backgroundYPos = 400;

	void ISSLocation::displayJSONValue(web::json::value ISSData);
	void update();
	pplx::task<void> requestISSLocation();

};

