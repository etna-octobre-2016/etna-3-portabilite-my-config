#ifndef _LINUXOS_H_
#define _LINUXOS_H_

#include "header.h"

class Linuxos : public Os
{
public:
    Linuxos();
    std::string getName();
    int getArchitecture();
};

#endif