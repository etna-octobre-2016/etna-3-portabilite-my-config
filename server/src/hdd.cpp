#include "../header/header.h"

using namespace std;

Hdd::Hdd()
{
    totalcapacity = 0;
}

uint64_t Hdd::getTotalCapacity()
{
    #ifdef _WIN32
        int dr_type = 99;
        char dr_avail[256];
        char *temp = dr_avail;
        GetLogicalDriveStrings(256, dr_avail);
        __int64 ttlspc, frspc;
        while(*temp != NULL)
        {
            GetDiskFreeSpaceEx(temp, 0, (PULARGE_INTEGER)&ttlspc, (PULARGE_INTEGER)&frspc);
            totalcapacity += ttlspc;
            temp += lstrlen(temp) + 1;
        }
        totalcapacity = totalcapacity / 1024 / 1024;
    #elif __APPLE__
        struct statfs statf;
        statfs(".", &statf);
        totalcapacity = statf.f_blocks;
    #else
        totalcapacity = 0;
    #endif
    
    return totalcapacity;
}