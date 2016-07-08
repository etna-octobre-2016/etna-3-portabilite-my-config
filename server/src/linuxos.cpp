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
    struct utsname system;
    string architectureName;
    int architecture;

    uname(&system);
    architectureName = system.machine;
    if (architectureName.find("64") != string::npos)
    {
        architecture = 64;
    }
    else
    {
        architecture = 32;
    }
    return architecture;
}





