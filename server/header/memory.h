#ifndef _MEMORY_H_
#define _MEMORY_H_

#include "header.h"

class Memory
{
    protected:
    uint64_t totalram;
    unsigned int freeram;
    unsigned int pourcentusedram;
    
    public:
    virtual uint64_t getTotalRam() = 0;
    virtual unsigned int getFreeRam() = 0;
    virtual unsigned int getPourcentRam() = 0;
    static Memory *Memory::getInstance();
};

#endif