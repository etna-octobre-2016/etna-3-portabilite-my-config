#include "../header/header.h"

LinuxHdd::LinuxHdd()
{
}

uint64_t LinuxHdd::getTotalCapacity()
{
    return 1;
}

uint64_t LinuxHdd::getUsedCapacity()
{
    return 2;
}

std::vector<std::string> LinuxHdd::getListHardDrive()
{
    return std::vector<std::string>();
}



