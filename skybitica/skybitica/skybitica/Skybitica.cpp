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

	web::http::client::http_client getClient()
	{
		// Create http_client to send the request.
		return web::http::client::http_client(U("https://habitica.com/"));
	}

	web::uri_builder getUri()
	{
		// Build the URI and return it
		return web::uri_builder(U("/api/v2/user/tasks"));
	}

	void doRequest(web::http::http_request &request)
	{
		web::http::client::http_client client = getClient();

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

	}

	web::json::value createTask(BSFixedString questName, BSFixedString questID)
	{
		// Create json object with Habitica task information for body of request
		web::json::value jsonObject = web::json::value::object();

		// Add to Habitica Todo list
		jsonObject[U("type")] = web::json::value(U("todo"));

		// Make the Todo be displayed as the quest name
		jsonObject[U("text")] = web::json::value(convertToWideString(questName.data));

		//Make the ID of the Todo be the quest ID, so it can be accessed later
		jsonObject[U("id")] = web::json::value(convertToWideString(questID.data));

		// Set up Habitica tag object to add to body of request
		web::json::value habiticaTaskTag = web::json::value::object();
		habiticaTaskTag[U("skyrim")] = web::json::value(U("true"));
		jsonObject[U("tags")] = web::json::value(habiticaTaskTag);

		return jsonObject;
	}

	float AddQuestToHabitica(StaticFunctionTag *base, BSFixedString questName, BSFixedString questID) 
	{
		_MESSAGE("AddQuest() will return %f", 3.3);

		web::json::value task = createTask(questName, questID);
		web::uri_builder uri = getUri();

		// Create request with POST protocol
		web::http::http_request request(web::http::methods::POST);
		request.set_request_uri(uri.to_string());

		// Headers for Habitica authentication
		request.headers().add(U("x-api-user"), convertToWideString(API_USER));
		request.headers().add(U("x-api-key"), convertToWideString(API_KEY));
		request.set_body(task);

		doRequest(request);

		return 3.3;
	}

	void CompleteQuestInHabitica(StaticFunctionTag *base, BSFixedString questID)
	{
		// Create request with POST protocol
		web::http::http_request request(web::http::methods::POST);

		// Build the URI
		web::uri_builder uri = getUri();
		uri.append(convertToWideString(questID.data));
		uri.append(U("/up"));
		request.set_request_uri(uri.to_string());

		// Headers for Habitica authentication
		request.headers().add(U("x-api-user"), convertToWideString(API_USER));
		request.headers().add(U("x-api-key"), convertToWideString(API_KEY));

		doRequest(request);
	}

	bool RegisterFuncs(VMClassRegistry* registry) {
		registry->RegisterFunction(
			new NativeFunction2 <StaticFunctionTag, float, BSFixedString, BSFixedString>("AddQuestToHabitica", "Skybitica", SkybiticaNamespace::AddQuestToHabitica, registry));
		registry->RegisterFunction(
			new NativeFunction1 <StaticFunctionTag, void, BSFixedString>("CompleteQuestInHabitica", "Skybitica", SkybiticaNamespace::CompleteQuestInHabitica, registry));

		return true;
	}
} 
