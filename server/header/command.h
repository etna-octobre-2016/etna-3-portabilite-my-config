#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "header.h"

using namespace std;

class Command
{
private:
    FILE *fd;
    char buffer[512];
public:
    Command(const string &commandString);
    ~Command();
    string getStdout();
    friend ostream &operator<<(ostream &out, Command &c)
    {
        out << c.getStdout();
        return out;
    }
};

#endif
