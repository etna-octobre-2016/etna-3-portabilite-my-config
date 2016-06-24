#include "../header/header.h"
#include <sstream>
#include <sys/statvfs.h>

using namespace std;

Machdd::Machdd()
{
    
}

uint64_t Machdd::getTotalCapacity()
{
    totalcapacity = 0;
    //const uint GB = (1024 * 1024) * 1024;
    
    totalcapacity = totalcapacity / 1024 / 1024;
    
    return totalcapacity;
}

uint64_t Machdd::getUsedCapacity()
{
    uint64_t freespace;
    freespace = 0;
    usedCapacity = 0;
    /*int dr_type = 99;
    char dr_avail[256];
    char *temp = dr_avail;
    GetLogicalDriveStrings(256, dr_avail);
    __int64 ttlspc, frspc;
    while (*temp != NULL)
    {
        GetDiskFreeSpaceEx(temp, 0, (PULARGE_INTEGER)&ttlspc, (PULARGE_INTEGER)&frspc);
        freespace += frspc;
        temp += lstrlen(temp) + 1;
    }*/
    freespace = freespace / 1024 / 1024;
    
    usedCapacity = getTotalCapacity() - freespace;
    
    return usedCapacity;
}

vector<string> Machdd::getListHardDrive()
{
    //méthode rapide
    /*char volumes [75];
    
    FILE * p = popen("df -l | awk '{print $1}'","r+");
    string temp;
    while(fgets(volumes,sizeof(volumes),p) != NULL)
    {
        temp = volumes;
        if (temp.find("/") == 0)
        {
            hddList.push_back(volumes);
        }
    }
    pclose(p);
    */
    
    //méthode lente mais affichage des noms de volumes
    char volumes [75];
    
    FILE * p = popen("df -l | awk '{print $1}'","r+");
    FILE *pt;
    string temp;
    char tmp[100];
    char command[100];
    while(fgets(volumes,sizeof(volumes),p) != NULL)
    {
        temp = volumes;
        if (temp.find("/") == 0)
        {
            *std::remove(volumes, volumes+strlen(volumes), '\n') = '\0';
            snprintf(tmp, sizeof(tmp), "diskutil info %s | grep \"Volume Name:\" | awk '{print $3,$4}'",volumes);
            pt = popen(tmp, "r+");
            while(fgets(command,sizeof(command),pt) != NULL)
            {
                hddList.push_back(command);
            }
        }
    }
    pclose(p);
    return hddList;
}