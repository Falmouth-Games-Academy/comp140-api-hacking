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


// Retrieves a JSON value from an HTTP request.
pplx::task<void> RequestJSONValueAsync()
{
	// Tutorials used
	//	http://www.drdobbs.com/tools/json-and-the-microsoft-c-rest-sdk/240164821
	//  https://msdn.microsoft.com/en-us/library/jj950082.aspx
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

void IterateJSONValue()
{
	// JSON object
	json::value iss_position;
	iss_position[L"latitude"]; // = json::value::number(1);
	iss_position[L"latitude"]; // = json::value::number(1);

	for (auto iter = iss_position.as_object().cbegin(); iter != iss_position.as_object().cend(); ++iter)
	{
		const std::wstring &str = iter->first;
		const json::value &v = iter->second;

		std::wcout << L"String: " << str << L", Value: " << v.serialize() << std::endl;
	}
}

int wmain()
{
	std::wcout << L"Calling RequestJSONValueAsync..." << std::endl;
	RequestJSONValueAsync().wait();

	//std::wcout << L"Calling IterateJSONValue..." << std::endl;
	//IterateJSONValue();
}