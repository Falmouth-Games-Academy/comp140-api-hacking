// API Hacking Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Facebook.h"

#include"string"
#include"cpprest/http_client.h"
#include "cpprest/json.h"
#include "cpprest/http_client.h"
#include "cpprest/filestream.h"

using namespace pplx;
using namespace web;
//using namespace Platform;
//using namespace Windows::Foundation;
//using namespace Windows::Security::Authentication::Web;
//using namespace Windows::Storage;



facebook_client& facebook_client::instance()
{
	static facebook_client c;
	return c;

}

pplx::task<void> facebook_client::full_login(std::wstring scopes)
{
	http::uri_builder login_uri(L"https://www.facebook.com/dialog/oauth");
	login_uri.append_query(L"client_id", L"<1129645030421798>"); // App id
	login_uri.append_query(L"redirect_uri", L"https://www.facebook.com/connect/login_success.html");
	login_uri.append_query(L"scope", scopes);
	login_uri.append_query(L"display", L"popup");
	//Causes error c4716. Needs to return a value even though it's a void
}

int main()
{
	return 0;
}


