#include "Skybitica.h"
#include <cpprest/http_client.h>
#include <cpprest/http_headers.h>
#include <cpprest/filestream.h>

namespace SkybiticaNamespace {
	float AddQuest(StaticFunctionTag *base) 
	{
		_MESSAGE("AddQuest() will return %f", 3.3);

		// Create json object with Habitica task information for body of request
		web::json::value jsonObject = web::json::value::object();
		jsonObject[U("type")] = web::json::value(U("todo"));
		jsonObject[U("text")] = web::json::value(U("Test"));

		// Create http_client to send the request.
		web::http::client::http_client client(U("https://habitica.com/"));

		// Create request with POST protocol
		web::http::http_request request(web::http::methods::POST);

		// Build the URI
		web::uri_builder builder(U("/api/v2/user/tasks"));
		request.set_request_uri(builder.to_string());

		// Headers for Habitica authentication
		request.headers().add(U("x-api-user"), U("a972616c-5627-43fc-bc5e-3acef2642c22"));
		request.headers().add(U("x-api-key"), U("a6e0b3ce-97d8-43c6-b796-e6ed500ebce0"));
		request.set_body(jsonObject);

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
			new NativeFunction0 <StaticFunctionTag, float>("AddQuest", "Skybitica", SkybiticaNamespace::AddQuest, registry));

		return true;
	}
} 
