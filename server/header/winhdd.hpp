#ifndef _HDDWIN_H_
#define _HDDWIN_H_

#include "hdd.h"

class Winhdd : public Hdd
{
	public:
		Winhdd();
		uint64_t getTotalCapacity();
		uint64_t getUsedCapacity();
		std::vector<std::string> getListHardDrive();
};

#endif