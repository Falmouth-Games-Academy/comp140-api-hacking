#include"stdafx.h"
#include "cpprest/http_client.h"
#include "cpprest/filestream.h"

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

int main(int argc, char* argv[])
{
	//Using the casablanca Http Client Tutorial, currently just goes to the open notify page and saves it 
	
	//TODO: 
	//Make a JSON object
	//Handle results using JSON
	//Intergrate with COMP150 game

	auto fileStream = std::make_shared<ostream>();

	// Open stream to output file.
	pplx::task<void> requestTask = fstream::open_ostream(U("ISS_location.html")).then([=](ostream outFile)
	{
		*fileStream = outFile;

		// Create http_client to send the request.
		http_client client(U("http://api.open-notify.org/iss-now.json"));

		//Gets reults
		return client.request(methods::GET);
	})

		// Handle response headers arriving.
		.then([=](http_response response)
	{
		printf("Received response status code:%u\n", response.status_code());

		// Write response body into the file.
		return response.body().read_to_end(fileStream->streambuf());
	})

		// Close the file stream
		.then([=](size_t)
	{
		return fileStream->close();
	});

	try
	{
		requestTask.wait();
	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	return 0;
}