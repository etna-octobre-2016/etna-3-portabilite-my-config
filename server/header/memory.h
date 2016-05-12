#ifndef _MEMORY_H_
#define _MEMORY_H_

#include "header.h"

#ifdef __APPLE__
    #include <mach/vm_statistics.h>
    #include <mach/mach_types.h>
    #include <mach/mach_init.h>
    #include <mach/mach_host.h>
#endif

class Memory
{
    private:
    #ifdef _WIN32
        MEMORYSTATUSEX statex;
    #endif
    uint64_t totalram;
    unsigned int freeram;
    unsigned int pourcentusedram;
    
    public:
    Memory();
    uint64_t getTotalRam();
    unsigned int getFreeRam();
    unsigned int getPourcentRam();
};

#endif