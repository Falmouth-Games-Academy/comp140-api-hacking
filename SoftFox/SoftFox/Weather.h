#pragma once

#include "resource.h"

class Weather
{
public:
	Weather();
	~Weather();

	const char& weatherList;

	void findWeather();

private:
	std::string weatherDescription;
};