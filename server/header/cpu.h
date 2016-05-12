#ifndef _CPU_H_
#define _CPU_H_

#include "header.h"

class Cpu
{
    private:  
    unsigned int coresCount;
    uint64_t freq;
    std::string cpuinfo;
    
    public:
    Cpu();
    unsigned int getCoresCount();
    uint64_t getFreq();
    std::string getCpuInfo();
};
#endif