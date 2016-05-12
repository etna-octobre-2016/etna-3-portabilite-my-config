#include "../header/header.h"

using namespace std;

Socket::Socket()
{
    isConnected = 0;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1"); /* IP */
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
}

int Socket::connection()
{
    #ifdef _WIN32
        /* A implémenter */
        return (0);
    #else
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
        {
            isConnected = 1;
            return (1);
        }
    #endif

    return (0);
}