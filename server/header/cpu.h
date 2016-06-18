#ifndef _CPU_H_
#define _CPU_H_

#include "header.h"

class Cpu
{
    protected:  
    unsigned int coresCount;
    uint64_t freq;
    std::string cpuinfo;
    
    public:
    virtual unsigned int getCoresCount() = 0;
    virtual uint64_t getFreq() = 0;
    virtual std::string getCpuInfo() = 0;
    static Cpu *getInstance();
};
#endif