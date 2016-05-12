#include "../header/header.h"

using namespace std;

Client::Client()
{
    recsize         = sizeof(sin);
    is_connected    = 0;
}

void Client::stop()
{
    closesocket(sock);
    is_connected = 0;
}