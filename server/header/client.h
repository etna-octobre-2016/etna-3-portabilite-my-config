#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "header.h"

class Client
{
    
    public:
    SOCKADDR_IN sin;
    SOCKET      sock;
    socklen_t   recsize;
    int         is_connected;
    Client();
    void stop();
};

#endif