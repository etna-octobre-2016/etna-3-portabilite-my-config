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
};

/*
class Os
{
    private:  
    std::string name;
    int architecture;
    
    public:
    Os();
    std::string getName();
    int getArchitecture();
};
*/
#endif