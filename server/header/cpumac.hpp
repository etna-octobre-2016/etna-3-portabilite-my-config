#ifndef _CPUMAC_H_
#define _CPUMAC_H_

#include "cpu.h"

class Cpumac : public Cpu
{
    public:
    Cpumac();
    unsigned int getCoresCount();
    uint64_t getFreq();
    std::string getCpuInfo();
};

#endif