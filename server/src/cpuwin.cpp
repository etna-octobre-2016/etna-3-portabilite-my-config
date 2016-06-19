#include "../header/header.h"

using namespace std;

Cpuwin::Cpuwin()
{

}

unsigned int Cpuwin::getCoresCount()
{
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    
    coresCount =  sysInfo.dwNumberOfProcessors;
     
    return coresCount;   
}

uint64_t Cpuwin::getFreq()
{
    freq = 0;
    return freq;
}

string Cpuwin::getCpuInfo()
{
	int CPUInfo[4] = { -1 };
	
	unsigned   nExIds, i = 0;
	char CPUBrandString[0x40];
	__cpuid(CPUInfo, 0x80000000);
	nExIds = CPUInfo[0];
	for (i = 0x80000000; i <= nExIds; ++i)
	{
		__cpuid(CPUInfo, i);
		if (i == 0x80000002)
			memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000003)
			memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000004)
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	}
	cpuinfo = CPUBrandString;

    return cpuinfo;
}
