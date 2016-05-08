#pragma once

#include "stdafx.h"
#include "Weather.h"


using namespace utility;			// Common utilities like string conversions
using namespace web;				// Common features like URIs
using namespace web::http;			// Common HTTP functionality
using namespace web::http::client;		// HTTP client features
using namespace concurrency::streams;		// Asynchronous streams

/*Tutorial casablanca guidance from:
https://github.com/Microsoft/cpprestsdk
http://stackoverflow.com/questions/34960421/looping-through-a-list-of-objects
*/

Weather::Weather()
{
	weatherDescription = "";
}
Weather::~Weather() {}

void Weather::findWeather()
{
	// Get the base for the web search using unicode
	web::http::client::http_client client(U("http://api.openweathermap.org"));

	// Start building the URL
	web::uri_builder builder(U("/data/2.5/weather"));

	// Prompt for user input
	std::cout << "Enter a location\n";

	// Create a suitable unicode string conversions for user input
	std::wstring location;

	// Get user location input
	std::wcin >> location;

	// Search query by location
	builder.append_query(U("q"), location);

	// App ID added here
	builder.append_query(U("appid"), U("82e200ef6d4a970a6d799061a11ed93c"));

	// Start built Get request
	http_response response = client.request(methods::GET, builder.to_string()).get();

	// When the JSON information has been extracted set forecastJSON
	web::json::value forecastJSON = response.extract_json(true).get();

	// Look for weather array
	web::json::value forecastWeatherJSON = forecastJSON.at(U("weather"));

	// Go through JSON list
	if (forecastWeatherJSON.is_array())
	{
		for (size_t i = 0; i < forecastWeatherJSON.size(); i++)
		{
			web::json::value forecastDayJSON = forecastWeatherJSON[i];

			// Look for "main" in the array for JSON data
			web::json::value mainJSON = forecastDayJSON.at(U("main"));
			std::string weatherDescription = "";
			if (!mainJSON.is_null())
			{
				// Change the weather description
				weatherDescription = conversions::to_utf8string(mainJSON.as_string());
			}

			// Display the location weather 
			std::cout << "Weather is " << conversions::to_utf8string(weatherDescription) << std::endl;

			weatherList = weatherDescription.c_str;
		}
	}
}