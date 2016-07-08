#ifndef _HDDWIN_H_
#define _HDDWIN_H_

#include "hdd.h"

class Machdd : public Hdd
{
public:
    Machdd();
    uint64_t getTotalCapacity();
    uint64_t getUsedCapacity();
    std::vector<std::string> getListHardDrive();
};

#endif