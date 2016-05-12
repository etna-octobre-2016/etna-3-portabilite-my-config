#ifndef _HDD_H_
#define _HDD_H_

class Hdd
{
    private:
    uint64_t totalcapacity;
    uint64_t usedCapacity;
    
    public:
    Hdd();
    uint64_t getTotalCapacity();
    uint64_t getUsedCapacity();
};

#endif