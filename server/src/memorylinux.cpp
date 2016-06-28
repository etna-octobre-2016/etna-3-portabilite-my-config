#include "../header/header.h"

using namespace std;

Memorylinux::Memorylinux()
{
    sysinfo(&this->systemInfo);
}

uint64_t Memorylinux::getTotalRam()
{
    return this->systemInfo.totalram;
}

unsigned int Memorylinux::getFreeRam()
{
    return static_cast<unsigned int>(this->systemInfo.freeram);
}

unsigned int Memorylinux::getPourcentRam()
{
    double percentage;

    percentage = static_cast<double>(this->systemInfo.freeram) / static_cast<double>(this->systemInfo.totalram) * 100;
    return static_cast<unsigned int>(percentage);
}