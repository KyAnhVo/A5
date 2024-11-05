#include "CommandStack.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

CommandStack::~CommandStack()
{
    for (auto c : cmdArr)
        delete c;
}

void CommandStack::push(char* cmd, char* arg)
{
    char** newCmd = new char*[3];
    newCmd[0] = new char[strlen(cmd) + 1];
    newCmd[1] = new char[strlen(arg) + 1];
    strcpy(newCmd[0], cmd);
    strcpy(newCmd[1], arg);
    cmdArr.push_back(newCmd);
}

void CommandStack::push(std::string cmd, std::string arg) {
    this->push(cmd.c_str(), arg.c_str());
}

char** CommandStack::pop()
{
    if (cmdArr.empty())
    {
        std::cerr << "Empty stack" << std::endl;
        return nullptr;
    }
    char** ans = cmdArr.back();
    cmdArr.erase(cmdArr.end());

    return ans;
}

bool CommandStack::isEmpty() const
{
    return cmdArr.empty();
}

bool CommandStack::notEmpty() const
{
    return !cmdArr.empty();
}