#include"stdafx.h"
#include "cpprest/http_client.h"
#include "cpprest/filestream.h"
#include <iostream>
#include <cpprest/json.h>


using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams


void DisplayJSONValue(json::value ISSData)
{
	if (!ISSData.is_null())
	{
		for (auto iter = ISSData.as_object().cbegin(); iter != ISSData.as_object().cend(); ++iter)
		{
			// It is necessary to make sure that you get the value as const reference
			// in order to avoid copying the whole JSON value recursively (too expensive for nested objects)
			const json::value &key = json::value::string(iter->first);
			const json::value &value = iter->second;

			if (value.is_object() || value.is_array())
			{
				// We have an object with children or an array
				if ((!key.is_null()) && (key.is_string()))
				{
					std::wcout << L"Parent: " << key.as_string() << std::endl;
				}
				// Loop over each element in the object by calling DisplayJSONValue
				DisplayJSONValue(value);
				if ((!key.is_null()) && (key.is_string()))
				{
					std::wcout << L"End of Parent: " << key.as_string() << std::endl;
				}
			}
			else
			{
				// Always display the value as a string
				std::wcout << L"Key: " << key.serialize() << L", Value: " << value.serialize() << std::endl;
			}
		}
	}
}


// Retrieves a JSON value from an HTTP request.
pplx::task<void> RequestJSONValueAsync()
{
	/* Tutorials used
	- http://www.drdobbs.com/tools/json-and-the-microsoft-c-rest-sdk/240164821
	- https://msdn.microsoft.com/en-us/library/jj950082.aspx */


	http_client client(L"http://api.open-notify.org/iss-now.json");
	return client.request(methods::GET).then([](http_response response) -> pplx::task<json::value>
	{
		if (response.status_code() == status_codes::OK)
		{
			return response.extract_json();
		}
		return pplx::task_from_result(json::value());
	})
		.then([](pplx::task<json::value> previousTask)
	{
		try
		{
			const json::value& v = previousTask.get();
			// JSON object
			std::cout << "Success" << std::endl;
			DisplayJSONValue(v);
			std::cout << "Success 2" << std::endl;
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


int wmain()
{
	std::wcout << L"Calling RequestJSONValueAsync..." << std::endl;
	RequestJSONValueAsync().wait();
}