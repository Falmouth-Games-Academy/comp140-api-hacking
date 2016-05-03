#include "HabiticaConnector.h"


HabiticaConnector::HabiticaConnector()
	: baseUri((U("/api/v2/user/tasks"))),
	client(U("https://habitica.com/"))
{
}

HabiticaConnector::~HabiticaConnector()
{
}

web::http::status_code HabiticaConnector::doRequest(web::http::http_request request)
{
	// Headers for Habitica authentication
	request.headers().add(U("x-api-user"), API_USER);
	request.headers().add(U("x-api-key"), API_KEY);

	// Make HTTP request as asynchronous task
	requestTask = client.request(request).then([=](web::http::http_response response)
	{
		_MESSAGE("Received response status code:%u\n", response.status_code());
		return response.status_code();
	});

	// Wait for all the outstanding I/O to complete and handle any exceptions
	try
	{
		requestTask.wait();
	}
	catch (const std::exception &e)
	{
		_MESSAGE("Error exception:%s\n", e.what());
	}

	return requestTask.get();
}

web::json::value HabiticaConnector::createTaskBody(std::wstring taskName, std::wstring taskID)
{
	// Create json object with Habitica task information for body of request
	web::json::value jsonObject = web::json::value::object();

	// Add to Habitica Todo list
	jsonObject[U("type")] = web::json::value(U("todo"));

	// Make the task be displayed as the quest name
	jsonObject[U("text")] = web::json::value(taskName);

	//Make the ID of the task be the quest ID, so it can be accessed later
	jsonObject[U("id")] = web::json::value(taskID);

	// Set up Habitica tag object to add to body of request
	web::json::value habiticaTaskTag = web::json::value::object();
	habiticaTaskTag[U("skyrim")] = web::json::value(U("true"));
	jsonObject[U("tags")] = web::json::value(habiticaTaskTag);

	return jsonObject;
}

bool HabiticaConnector::taskExists(std::wstring questID)
{
	web::uri_builder requestUri = baseUri;
	requestUri.append(questID);

	web::http::http_request request(web::http::methods::GET);
	request.set_request_uri(requestUri.to_string());

	web::http::status_code responseStatus = doRequest(request);

	if (responseStatus == 200)
	{
		_MESSAGE("Task exists");
		return true;
	}
	else
	{
		_MESSAGE("Task doesn't exist");
		return false;
	}
}

bool HabiticaConnector::requestTaskDone()
{
	return requestTask.is_done();
}

web::http::status_code HabiticaConnector::addTask(std::wstring taskName, std::wstring taskID)
{
	_MESSAGE("AddQuest() will return %f", 3.3);
	web::json::value task = createTaskBody(taskName, taskID);

	// Create request with POST protocol
	web::http::http_request request(web::http::methods::POST);
	request.set_request_uri(baseUri.to_string());
	request.set_body(task);

	web::http::status_code responseStatus = doRequest(request);
	return responseStatus;
} 

web::http::status_code HabiticaConnector::completeTask(std::wstring taskName, std::wstring taskID)
{
	if (!taskExists(taskID))
	{
		addTask(taskName, taskID);
	}

	// Create request with POST protocol
	web::http::http_request request(web::http::methods::POST);

	// Build the URI
	web::uri_builder requestUri = baseUri;
	requestUri.append(taskID);
	requestUri.append(U("/up"));	//Completes the Habitica Todo
	request.set_request_uri(requestUri.to_string());

	web::http::status_code responseStatus = doRequest(request);
	return responseStatus;
}


