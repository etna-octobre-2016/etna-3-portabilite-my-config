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
            snprintf(tmp, sizeof(tmp), "diskutil info %s | grep \"Total Size:\" | awk '{print $5}'",volumes);
            pt = popen(tmp, "r+");
            while(fgets(command,sizeof(command),pt) != NULL)
            {
                *std::remove(command, command+strlen(command), '(') = ' ';
                totalcapacity += ::atof(command);
            }
        }
    }
    pclose(p);
    
    return totalcapacity;
}

uint64_t Machdd::getUsedCapacity()
{
    uint64_t freespace;
    freespace = 0;
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
            snprintf(tmp, sizeof(tmp), "diskutil info %s | grep \"Volume Free Space:\" | awk '{print $6}'",volumes);
            pt = popen(tmp, "r+");
            while(fgets(command,sizeof(command),pt) != NULL)
            {
                *std::remove(command, command+strlen(command), '(') = ' ';
                freespace += ::atof(command);
            }
        }
    }
    pclose(p);
    
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