#ifndef _CPUWIN_H_
#define _CPUWIN_H_

#include "header.h"

class Cpuwin : public Cpu
{
    public:
    Cpuwin();
    unsigned int getCoresCount();
    uint64_t getFreq();
    std::string getCpuInfo();
};

#endif