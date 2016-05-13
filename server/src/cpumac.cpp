#include "../header/header.h"

using namespace std;

Cpumac::Cpumac()
{
    
}

unsigned int Cpumac::getCoresCount()
{
    size_t size = sizeof(coresCount);
    sysctlbyname("hw.activecpu", &coresCount, &size, NULL, 0);
     
    return coresCount;   
}

uint64_t Cpumac::getFreq()
{
    size_t size = sizeof(freq);
    if(sysctlbyname("hw.cpufrequency", &freq, &size, NULL, 0) < 0)
    {
        perror("sysctl");
        }
    return freq;
}

string Cpumac::getCpuInfo()
{
    char buf[100];
    size_t buflen = 100;
    sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);
    cpuinfo = buf;
    return cpuinfo;
}
