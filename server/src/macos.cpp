#include "../header/header.h"

using namespace std;

Macos::Macos()
{
    
}

string Macos::getName()
{
    struct utsname sysinfo;
    uname(&sysinfo);
    name = sysinfo.release;
    if (name.find("15") != std::string::npos)
        name = "El Capitan";
    else if (name.find("14") != std::string::npos)
        name = "Yosemite";
    else if (name.find("13") != std::string::npos)
        name = "Mavericks";
    else
        name = "unknow";
    
    return name;
}

int Macos::getArchitecture()
{
    struct utsname sysinfo;
    uname(&sysinfo);
    string arch = sysinfo.machine;
    if (arch.find("64") != std::string::npos)
        architecture = 64;
    else
        architecture = 32;
    return architecture;
}