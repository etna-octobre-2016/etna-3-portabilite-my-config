#ifndef _CPULINUX_H_
#define _CPULINUX_H_

#include "cpu.h"

class Cpulinux : public Cpu
{
    public:
    Cpulinux();
    unsigned int getCoresCount();
    uint64_t getFreq();
    std::string getCpuInfo();
};

#endif