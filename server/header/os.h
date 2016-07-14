#ifndef _OS_H_
#define _OS_H_

#include "header.h"

class Os
{
    protected:
    std::string name;
    int architecture;

    public:
    virtual std::string getName() = 0;
    virtual int getArchitecture() = 0;
    static Os *getInstance();
};
#endif
