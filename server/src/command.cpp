#include "../header/command.h"

Command::Command(const string &commandString)
{
    this->fd = popen(commandString.c_str(), "r");
    if (this->fd == NULL)
    {
        throw string("couldn't execute command");
    }
}

Command::~Command()
{
    pclose(this->fd);
}

string Command::getStdout()
{
    stringstream output;
    string outputStr;

    while (fgets(this->buffer, sizeof(this->buffer), this->fd) != NULL)
    {
        output << this->buffer;
    }
    outputStr = output.str();
    outputStr.pop_back();
    return outputStr;
}
