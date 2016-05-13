#include "../header/header.h"

using namespace std;

Cpulinux::Cpulinux()
{

}

unsigned int Cpulinux::getCoresCount()
{
    coresCount = 0;
     
    return coresCount;   
}

uint64_t Cpulinux::getFreq()
{
    freq = 0;
     
    return freq;
}

string Cpulinux::getCpuInfo()
{
    cpuinfo  = "";
    return cpuinfo;
}
