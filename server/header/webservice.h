#include "header.h"

using namespace std;

class Webservice
{
private:
	int port;
	vector<std::shared_ptr<restbed::Resource>> resources;

public:
	Webservice();
	~Webservice();
	void addRoute(const string &method, const string &uri, const function<void(const shared_ptr<restbed::Session>)> &callback);
	void setPort(int port);
	void start();
};

