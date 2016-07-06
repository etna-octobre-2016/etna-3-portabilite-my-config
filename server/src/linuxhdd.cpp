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
    char volumes [75];
        
    FILE *p = popen("df -l | awk '{print $1}'","r");
    string temp;
    while(fgets(volumes, sizeof(volumes) - 1, p) != NULL)
    {
        temp = volumes;
        if (temp.find("/") == 0)
        {
            //*std::remove(volumes, strlen(volumes), '\n');            
            strtok(volumes, "\n");
            hddList.push_back(volumes);
        }
    }
    pclose(p);
    return hddList;
}



