#ifndef _SOCKET_H_
#define _SOCKET_H_

#include "header.h"
#include "client.h"

class Socket
{
    private:  
    int         is_running;
    SOCKADDR_IN sin;
    SOCKET      sock;
    socklen_t   recsize;
    Client      client;
    int start();
    void stop();
    void accept_client();
    
    public:
    Socket();
    int run();
};
#endif