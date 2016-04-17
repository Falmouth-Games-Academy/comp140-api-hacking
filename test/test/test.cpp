// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cpprest/http_client.h>
#include <cpprest/http_headers.h>
#include <cpprest/filestream.h>

void addTodo()
{
	auto fileStream = std::make_shared<concurrency::streams::ostream>();

	// Open stream to output file.
	pplx::task<void> requestTask = concurrency::streams::fstream::open_ostream(U("results.html")).then([=](concurrency::streams::ostream outFile)
	{
		*fileStream = outFile;

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
		request.headers().add(U("x-api-key"), U(""));
		request.set_body(jsonObject);

		return client.request(request);
	})

		// Handle response headers arriving.
		.then([=](web::http::http_response response)
	{
		printf("Received response status code:%u\n", response.status_code());

		// Write response body into the file.
		return response.body().read_to_end(fileStream->streambuf());
	})

		// Close the file stream.
		.then([=](size_t)
	{
		return fileStream->close();
	});

	// Wait for all the outstanding I/O to complete and handle any exceptions
	try
	{
		requestTask.wait();
	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}
}

int main()
{
	addTodo();
	return 0;
}

