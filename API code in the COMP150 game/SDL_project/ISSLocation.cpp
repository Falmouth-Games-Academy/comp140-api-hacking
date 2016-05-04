#include "stdafx.h"
#include "ISSLocation.h"

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

ISSLocation::ISSLocation()
{
}


ISSLocation::~ISSLocation()
{
}


void ISSLocation::displayJSONValue(web::json::value ISSData)
{ //Extracts infomation from the JSON value and saves it in variables 
	if (!ISSData.is_null())
	{ //Only runs if there is data to extract
		for (auto iter = ISSData.as_object().cbegin(); iter != ISSData.as_object().cend(); ++iter)
		{
			const json::value &key = json::value::string(iter->first); //Key is the data name
			const json::value &value = iter->second; //Value is the data itself

			if (value.is_object() || value.is_array())
			{
				if ((!key.is_null()) && (key.is_string()))
				{
					std::wcout << L"Parent: " << key.as_string() << std::endl;
					//Parent is the object in this case iss_position
					//Parent contains the latitude & longitude
				}
				displayJSONValue(value);
				if ((!key.is_null()) && (key.is_string()))
				{
					std::wcout << L"End of Parent: " << key.as_string() << std::endl;
				}
			}
			else
			{ //Saves values as variables
				if (key.serialize() == (L"\"timestamp""\""))
				{
					updateTime = value.as_integer();
				}
				else if (key.serialize() == (L"\"longitude""\""))
				{
					longitude = value.as_double();
				}
				else if (key.serialize() == (L"\"latitude""\""))
				{
					latitude = value.as_double();
				}
			}
		}
	}
}


pplx::task<void> ISSLocation::requestJSONValueAsync()
{ // Sends request to open notify and if successful extracts the JSON data in to a json value 
	http_client client(L"http://api.open-notify.org/iss-now.json");
	return client.request(methods::GET).then([](http_response response) -> pplx::task<json::value>
	{
		if (response.status_code() == status_codes::OK)
		{ //If connection is successful it extracts JSON
			return response.extract_json();
		}
		return pplx::task_from_result(json::value());
	})
		.then([&](pplx::task<json::value> previousTask)
	{
		try
		{
			const json::value& issLocation = previousTask.get();
			// JSON object
			displayJSONValue(issLocation);
		}
		catch (const http_exception& e)
		{
			// Error catch
			std::wostringstream ss;
			ss << e.what() << std::endl;
			std::wcout << ss.str();
		}
	});
}

void ISSLocation::update()
{
	if (updateTime > previousUpdateTime + 3)
	{// Currently updates location 
		requestJSONValueAsync().wait();
		backgroundXPos = ((latitude / 90) * 800) + 1000; //800 = Screen height
		backgroundYPos = ((longitude / 180) * 800) + 1000; //800 = Screen width

	}
}
