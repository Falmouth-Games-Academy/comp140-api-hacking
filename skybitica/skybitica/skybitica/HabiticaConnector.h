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
	web::http::status_code addTask(std::wstring taskName, std::wstring taskID);
	web::http::status_code completeTask(std::wstring taskName, std::wstring taskID);

private:
	web::uri_builder baseUri;
	web::http::client::http_client client; 
	
	web::http::status_code doRequest(web::http::http_request request);
	web::json::value createTaskBody(std::wstring taskName, std::wstring taskID);
	bool taskExists(std::wstring taskID);
};

