#ifndef _MACOS_H_
#define _MACOS_H_

#include "os.h"

class Macos : public Os
{
    public:
    Macos();
    std::string getName();
    int getArchitecture();
};

#endif