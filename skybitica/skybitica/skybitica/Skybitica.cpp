#include "Skybitica.h"
#include "keys.h"
#include <cpprest/http_client.h>
#include <cpprest/http_headers.h>
#include <cpprest/filestream.h>

namespace SkybiticaNamespace {

	// Function for converting string types from here http://stackoverflow.com/a/10738141
	std::wstring convertToWideString(const std::string& str)
	{
		int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
		std::wstring wstrTo(size_needed, 0);
		MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
		return wstrTo;
	}

	float AddQuest(StaticFunctionTag *base, BSFixedString questName) 
	{
		_MESSAGE("AddQuest() will return %f", 3.3);

		// Create json object with Habitica task information for body of request
		web::json::value jsonObject = web::json::value::object();

		web::json::value habiticaTaskTag = web::json::value::object();
		habiticaTaskTag[U("skyrim")] = web::json::value(U("true"));

		jsonObject[U("type")] = web::json::value(U("todo"));
		jsonObject[U("text")] = web::json::value(convertToWideString(questName.data));
		jsonObject[U("tags")] = web::json::value(habiticaTaskTag);

		// Create http_client to send the request.
		web::http::client::http_client client(U("https://habitica.com/"));

		// Create request with POST protocol
		web::http::http_request request(web::http::methods::POST);

		// Build the URI
		web::uri_builder builder(U("/api/v2/user/tasks"));
		request.set_request_uri(builder.to_string());

		// Headers for Habitica authentication
		request.headers().add(U("x-api-user"), convertToWideString(API_USER));
		request.headers().add(U("x-api-key"), convertToWideString(API_KEY));
		request.set_body(jsonObject);

		// Make HTTP request as asynchronous task
		pplx::task<web::http::http_response> response = client.request(request);

		// Wait for all the outstanding I/O to complete and handle any exceptions
		try
		{
			response.wait();
		}
		catch (const std::exception &e)
		{
			_MESSAGE("Error exception:%s\n", e.what());
		}

		return 3.3;
	}

	bool RegisterFuncs(VMClassRegistry* registry) {
		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, float, BSFixedString>("AddQuest", "Skybitica", SkybiticaNamespace::AddQuest, registry));

		return true;
	}
} 
