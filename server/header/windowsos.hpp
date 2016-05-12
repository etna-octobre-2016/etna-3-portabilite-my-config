#ifndef _WINDOWSOS_H_
#define _WINDOWSOS_H_

#include "os.h"

class Windowsos : public Os
{
    public:
    Windowsos();
    std::string getName();
    int getArchitecture();
};

#endif