#include "../header/header.h"

using namespace std;

Memorywin::Memorywin()
{
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
}

uint64_t Memorywin::getTotalRam()
{
    totalram = statex.ullTotalPhys/1024;
    
    return totalram;
}

unsigned int Memorywin::getFreeRam()
{
    freeram = statex.ullAvailPhys/1024;

    return freeram;
}

unsigned int Memory::getPourcentRam()
{
    pourcentusedram = statex.dwMemoryLoad;
    return pourcentusedram;
}