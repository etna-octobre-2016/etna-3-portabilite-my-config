#include "../header/header.h"

LinuxHdd::LinuxHdd()
{
}

uint64_t LinuxHdd::getTotalCapacity()
{
    char res [100];

    FILE *pt = popen("df | grep '^/dev/[hs]d' | awk '{s+=$2} END {print s}'", "r");
    fread(res, 1, sizeof(res) - 1, pt);
    fclose(pt);
    totalcapacity = ::atof(res);
    return totalcapacity;
}

uint64_t LinuxHdd::getUsedCapacity()
{
    char res [100];
    
    FILE *pt = popen("df | grep '^/dev/[hs]d' | awk '{s+=$3} END {print s}'", "r");
    fread(res, 1, sizeof(res) - 1, pt);
    fclose(pt);
    usedCapacity = ::atof(res);
    return usedCapacity;
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



