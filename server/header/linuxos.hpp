#ifndef _LINUXOS_H_
#define _LINUXOS_H_

#include "os.h"

class Linuxsos : public Os
{
    public:
    Linuxos();
    std::string getName();
    int getArchitecture();
};

#endif