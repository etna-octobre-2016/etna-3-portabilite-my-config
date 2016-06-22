#ifndef _HDD_H_
#define _HDD_H_

#include "header.h"
#include <vector>


class Hdd
{
    protected:
    uint64_t totalcapacity;
    uint64_t usedCapacity;
	std::vector<std::string> hddList;
    
    public:
    virtual uint64_t getTotalCapacity() = 0;
    virtual uint64_t getUsedCapacity() = 0;
	virtual std::vector<std::string> getListHardDrive() = 0;
};

#endif