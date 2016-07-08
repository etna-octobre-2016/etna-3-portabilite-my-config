#include "header.h"

class LinuxHdd : public Hdd
{
public:
    LinuxHdd();
    uint64_t getTotalCapacity();
    uint64_t getUsedCapacity();
    std::vector<std::string> getListHardDrive();
};