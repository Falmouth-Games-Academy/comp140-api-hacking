//! A class for connecting to the Habitica API
/*!
  This class contains methods for connecting to the Habitica
  API using the C++ Rest SDK.
*/

#pragma once
#include "stdafx.h"
#include "keys.h"
#include "tools.h"
#include <cpprest/http_client.h>
#include <cpprest/http_headers.h>
#include <cpprest/filestream.h>

class HabiticaConnector
{
public:
	HabiticaConnector();
	~HabiticaConnector();

	//! Adds a task to Habitica's Todo list
	/*!
	  This method adds a task, which is assigned the provided
	  name and ID, to the Habitica todo list, using a POST request.
	  The ID is what will be used to later refer to the task on
	  Habitica.
	*/
	void addTask(std::wstring taskName, std::wstring taskID);

	//! Complete a task on Habitica's Todo list
	/*!
	  This method completes the task with the provided ID on the
	  Habitica todo list, using a POST request.
	*/
	void completeTask(std::wstring taskName, std::wstring taskID);

	//! Delete a task from Habitica's Todo list
	/*!
	  This method deletes the task with the provided ID from the
	  Habitica Todo list.
	*/
	void deleteTask(std::wstring taskID);

	//! Return the result of the request associated with a Habitica ID
	/*!
	  This method returns the HTTP status code received from the last
	  request that dealt with the specified ID. 
	*/
	web::http::status_code getResult(std::wstring taskID);


private:
	//! The uri that will be included on all requests
	/*!
	  This is the uri that will be included on all requests.
	  It should be set corresponding to the instructions in
	  the Habitica API documentation.
	  As a uri_builder type, extra information required for
	  some types of request can be appended to it.
	*/
	web::uri_builder apiUri;

	//! The http client that will be used to connect to the service
	/*!
	  This is the http client that will be used to connect to
	  Habitica.
	*/
	web::http::client::http_client client; 
	
	//! Performs the given http request.
	/*!
	  This method performed the provided http request as an
	  asynchronous task. When the task is complete, it will add
	  the response code and taskID to finishedRequestTasks, in order
	  to record the result of the request.
	*/
	void doRequest(web::http::http_request request, std::wstring taskID);

	//! Creates the JSON object containing Habitica task information
	/*!
	  This method creates the JSON object containing  information about
	  the Habitica Todo task to be added. It will include the given name
	  and ID, whilst ensuring that the task is a "todo" type and assigning it
	  a Skyrim tag.
	*/
	web::json::value createTaskBody(std::wstring taskName, std::wstring taskID);

	//! A map containing Habitica task IDs and response codes
	/*!
	  This map contains the Habitica task IDs (as std::wstring) for each request that has sent
	  a request to the Habitica API, corresponding to the response code received
	  from the request (as web::http::status_code).
	  The entries will only be added to the map after the HTTP request has finished.
	*/
	std::map<std::wstring, web::http::status_code> finishedRequestTasks;
};

