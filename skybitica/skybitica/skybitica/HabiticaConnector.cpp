#include "HabiticaConnector.h"


HabiticaConnector::HabiticaConnector()
	: apiUri((U("/api/v2/user/tasks"))),
	client(U("https://habitica.com/"))
{
}

HabiticaConnector::~HabiticaConnector()
{
}

void HabiticaConnector::doRequest(web::http::http_request request, std::wstring taskID)
{
	// Headers for Habitica authentication
	request.headers().add(U("x-api-user"), API_USER);
	request.headers().add(U("x-api-key"), API_KEY);

	// Make HTTP request as asynchronous task
	pplx::task<web::http::status_code> requestTask = client.request(request).then([=](web::http::http_response response)
	{
		_MESSAGE("Received response status code:%u\n", response.status_code());
		// Log the status code of the finished request
		finishedRequestTasks[taskID] = response.status_code();
        return response.status_code();
	});
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

web::http::status_code HabiticaConnector::getResult(std::wstring taskID)
{
	_MESSAGE("Received response status code task blah:%u\n", finishedRequestTasks[taskID]);
	return finishedRequestTasks[taskID];
}

void HabiticaConnector::addTask(std::wstring taskName, std::wstring taskID)
{
	web::json::value task = createTaskBody(taskName, taskID);

	// Create request with POST protocol
	web::http::http_request request(web::http::methods::POST);
	request.set_request_uri(apiUri.to_string());
	request.set_body(task);

	doRequest(request, taskID);
} 

void HabiticaConnector::completeTask(std::wstring taskName, std::wstring taskID)
{
	// Create request with POST protocol
	web::http::http_request request(web::http::methods::POST);

	// Build the URI
	web::uri_builder requestUri = apiUri;
	requestUri.append(taskID);
	requestUri.append(U("/up"));	//Completes the Habitica Todo
	request.set_request_uri(requestUri.to_string());

	doRequest(request, taskID);
}


void HabiticaConnector::deleteTask(std::wstring taskID)
{
	// Create request with DELETE protocol
	web::http::http_request request(web::http::methods::DEL);
	
	web::uri_builder requestUri = apiUri;
	requestUri.append(taskID);
	request.set_request_uri(requestUri.to_string());
	doRequest(request, taskID);
}