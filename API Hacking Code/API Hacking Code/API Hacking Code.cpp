#include"stdafx.h"

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

//Console application that requests the ISS Location then extracts the data from JSON object and stores it in variables

double longitude, latitude; //Variables to store the data in

// Stores and prints the latitude and 
void DisplayJSONValue(json::value ISSData)
{
	if (!ISSData.is_null())
	{
		for (auto iter = ISSData.as_object().cbegin(); iter != ISSData.as_object().cend(); ++iter)
		{ //Loops through every key in the JSON object
			const json::value &key = json::value::string(iter->first);
			const json::value &value = iter->second;

			if (value.is_object() || value.is_array())
			{
				if ((!key.is_null()) && (key.is_string()))
				{
					std::wcout << L"Parent: " << key.as_string() << std::endl;
					//Parent is the object in this case iss_position
					//Parent contains the latitude & longitude
				}
				DisplayJSONValue(value);
				if ((!key.is_null()) && (key.is_string()))
				{
					std::wcout << L"End of Parent: " << key.as_string() << std::endl;
				}
			}
			else
			{

				if (key.serialize() == (L"\"longitude""\""))
				{ // Stores the longitude value in a variable 
					longitude = value.as_double();
				}
				else if (key.serialize() == (L"\"latitude""\""))
				{ // Stores the latitude value in a variable 
					latitude = value.as_double();
				}
				std::wcout << L"Key: " << key.serialize() << L", Value: " << value.serialize() << std::endl;
			}
		}
	}
}


// Retrieves a JSON value from an HTTP request.
pplx::task<void> RequestISSLocation()
{
	http_client client(L"http://api.open-notify.org/iss-now.json");
	return client.request(methods::GET).then([](http_response response) -> pplx::task<json::value>
	{
		if (response.status_code() == status_codes::OK)
		{  // If successful extract JSON
			return response.extract_json();
		}
		return pplx::task_from_result(json::value());
	})
		.then([](pplx::task<json::value> previousTask)
	{
		try
		{
			const json::value& issPosition = previousTask.get();
			// issPositionis the JSON object
			DisplayJSONValue(issPosition);
			std::cout << "Success" << std::endl;
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


int main()
{
	std::cout << "Requesting ISS location. Please wait." << std::endl;
	RequestISSLocation().wait();  //wait() waits until the function has finished
}