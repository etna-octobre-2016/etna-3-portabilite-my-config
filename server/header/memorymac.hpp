#ifndef _MEMORYMAC_H_
#define _MEMORYMAC_H_

#include "memory.h"

#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

class Memorymac : public Memory
{   
    public:
    Memorymac();
    uint64_t getTotalRam();
    unsigned int getFreeRam();
    unsigned int getPourcentRam();
};

#endif