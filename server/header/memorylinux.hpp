#ifndef _MEMORYLINUX_H_
#define _MEMORYLINUX_H_

#include "memory.h"

class Memorylinux : public Memory
{
private:
    struct sysinfo systemInfo;
public:
    Memorylinux();
    uint64_t getTotalRam();
    unsigned int getFreeRam();
    unsigned int getPourcentRam();
};

#endif