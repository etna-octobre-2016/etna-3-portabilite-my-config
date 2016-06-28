#include "../header/header.h"

using namespace std;

Linuxos::Linuxos()
{
}

string Linuxos::getName()
{
    Command cmd("lsb_release -ds");

    return cmd.getStdout();
}

int Linuxos::getArchitecture()
{
    return 64;
}





