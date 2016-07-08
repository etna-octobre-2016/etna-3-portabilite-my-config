#include "../header/header.h"

using namespace std;

Cpulinux::Cpulinux()
{

}

unsigned int Cpulinux::getCoresCount()
{
    int test;
    FILE * fp;
    char res[128];
    fp = popen("/bin/cat /proc/cpuinfo |grep -c '^processor'","r");
    fread(res, 1, sizeof(res)-1, fp);
    fclose(fp);
    coresCount = res[0] - '0';
    return coresCount;   
}

uint64_t Cpulinux::getFreq()
{
    freq = 0;
     
    return freq;
}

string Cpulinux::getCpuInfo()
{
    FILE *fp;
    char res[128];
    fp = popen("/bin/cat /proc/cpuinfo |grep -m 1 \"model name\" | awk '{ print substr($0, index($0,$4)) }'", "r");
    fread(res, 1, sizeof(res) - 1, fp);
    fclose(fp);
    cpuinfo = res;
    return cpuinfo;
}
