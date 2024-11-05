#ifndef COMMAND_STACK_H
#define COMMAND_STACK_H

#include <vector>
#include <iostream>
#include <string>

class CommandStack
{
private:
    std::vector<char**> cmdArr;

public:
    CommandStack() {}
    ~CommandStack();
    void push(char*, char*);
    void push(std::string, std::string);
    char** pop();
    bool isEmpty() const;
    bool notEmpty() const;
};

#endif