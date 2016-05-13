#include "../header/header.h"

using namespace std;

Memorylinux::Memorylinux()
{
}

uint64_t Memorylinux::getTotalRam()
{
    totalram = 0;
    
    return totalram;
}

unsigned int Memorylinux::getFreeRam()
{
    freeram = 0;
    return freeram;
}

unsigned int Memorylinux::getPourcentRam()
{
    pourcentusedram = 0;
    return pourcentusedram;
}