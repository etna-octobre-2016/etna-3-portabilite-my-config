#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#ifdef _WIN32
    #include <windows.h>
    #include <winsock2.h>
    typedef int socklen_t;
    #include "memorywin.hpp"
#else
    #include <sys/utsname.h>
    #include <sys/types.h>
    #include <sys/sysctl.h>
    #include <sys/param.h>
    #include <sys/mount.h>

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
#include "cpu.h"
#include "os.h"
#include "memory.h"
#include "hdd.h"
#include "client.h"
#include "socket.h"
#include "macos.hpp"
#include "windowsos.hpp"
#include "cpumac.hpp"
#include "cpuwin.hpp"
#include "cpulinux.hpp"
#include "memorymac.hpp"
#include "memorylinux.hpp"

#define WAIT_SEC        0
#define WAIT_USEC       20
#define PORT            1280

#endif