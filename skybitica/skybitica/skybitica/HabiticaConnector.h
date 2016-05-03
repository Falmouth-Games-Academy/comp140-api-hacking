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
	void addTask(std::wstring taskName, std::wstring taskID);
	void completeTask(std::wstring taskName, std::wstring taskID);
	void deleteTask(std::wstring taskID);
	web::http::status_code getResult(std::wstring taskID);

private:
	web::uri_builder baseUri;
	web::http::client::http_client client; 
	
	void doRequest(web::http::http_request request, std::wstring taskID);
	web::json::value createTaskBody(std::wstring taskName, std::wstring taskID);

	std::map<std::wstring, web::http::status_code> finishedRequestTasks;
};

