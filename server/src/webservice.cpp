#include "../header/header.h"

using namespace std;

Webservice::Webservice()
{
}

Webservice::~Webservice()
{
}

void Webservice::addRoute(const string &method, const string &uri, const function<void(const shared_ptr<restbed::Session>)>&callback)
{
	auto resource = make_shared<restbed::Resource>();
	resource->set_path(uri);
	resource->set_method_handler(method, callback);
	this->resources.push_back(resource);
}

void Webservice::setPort(int port)
{
	this->port = port;
}

void Webservice::start()
{
	auto settings = make_shared<restbed::Settings>();
	vector<std::shared_ptr<restbed::Resource>>::iterator item;
	restbed::Service service;

	settings->set_port(this->port);
	settings->set_default_header("Connection", "close");
	for (item = this->resources.begin(); item != this->resources.end(); item++)
	{
		service.publish(*item);
	}
	service.start(settings);
}

