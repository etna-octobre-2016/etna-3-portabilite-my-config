#ifndef _MEMORYWIN_H_
#define _MEMORYWIN_H_

#include "header.h"

class Memorywin : public Memory
{
    private:
    MEMORYSTATUSEX statex;
    
    public:
    Memorywin();
    uint64_t getTotalRam();
    unsigned int getFreeRam();
    unsigned int getPourcentRam();
};

#endif