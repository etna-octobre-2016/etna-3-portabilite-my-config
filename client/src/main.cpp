#include "../header/header.h"
using namespace std;

int main()
{
    /* Connexion */
    Socket sck;
    if (sck.connection() == 1) {
        cout << "connection ok" << endl;
    } else {
        cout << "connection ko" << endl;
    }
   
    return 0;
}




