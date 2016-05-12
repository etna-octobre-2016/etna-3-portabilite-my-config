#include "../header/header.h"

using namespace std;

Socket::Socket()
{
    is_running          = 0;
    sock                = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family      = AF_INET;
    sin.sin_port        = htons(PORT);
    recsize             = sizeof(sin);
    client              = Client();
}

int Socket::start()
{
    if (is_running < 1)
    {
        #ifdef _WIN32
            /* A implémenter */
        #else
            int sock_err;
            sock_err = bind(sock, (SOCKADDR*)&sin, recsize);

            if(sock != INVALID_SOCKET && sock_err != SOCKET_ERROR)
            {
                sock_err = listen(sock, 5);
                if(sock_err != SOCKET_ERROR)
                {
                    cout << "Le serveur est lancé" << endl;
                    is_running = 1;
                    return(1);
                }
            }
        #endif
    }

    cout << "Erreur lors du lancement du serveur" << endl;
    return (0);
}

int Socket::run()
{
    if (start() == 1) {
        while (is_running == 1) {
            /* Permet d'avoir qu'une connexion */
            if (client.is_connected != 1) {
                accept_client();
            }
        }
        stop();
        return (1);
    }
    return (0);
}

void Socket::stop()
{
    cout << "Le serveur est arreté" << endl;
    is_running = 0;
    closesocket(sock);
    client.stop();
}

void Socket::accept_client()
{
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);
    struct timeval tv = {WAIT_SEC, WAIT_USEC}; 

    if (select(sock + 1, &readfds , NULL , NULL , &tv) > 0) {
        client      = Client();
        client.sock = accept(sock, (SOCKADDR*)&client.sin, &client.recsize);

        if (client.sock != -1){
            client.is_connected = 1;
            cout << "Arrivée d'un nouveau client" << endl;
            is_running = 0;
        }
    }
}