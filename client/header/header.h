#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#ifdef _WIN32
    #include <windows.h>
    #include <winsock2.h>
    typedef int socklen_t;
#else
    #include <sys/utsname.h>
    #include <sys/types.h>
    #include <sys/sysctl.h>

    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>

    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(param) close(param)

    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
#endif

#include <stdio.h>
#include <stdlib.h> 
#include <string>

#include "socket.h"
#define PORT    1280

#endif