#ifndef _SOCKET_H_
#define _SOCKET_H_

#include "header.h"

class Socket
{
    private:  
    int         isConnected;
    SOCKADDR_IN sin;
    SOCKET      sock;
    
    public:
    Socket();
    int connection();
};
#endif