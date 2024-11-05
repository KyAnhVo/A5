#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "CommandStack.h"

int main(int argc, char** argv)
{
    if (argc < 3 || argc > 6)
    {
        printf("Incorrect amount of arguments\n");
        return 0;
    }

    // get all commands

    CommandStack commands;
    bool lastProcess = false, isParent = true;
    char** command;

    for (int i = 1; i < argc; i++)
    {
        std::stringstream ss(argv[i]);
        std::string command, arguments;

        ss >> command;
        std::getline(ss, arguments);

        commands.push(command, arguments);
    }
    
    // pipe between processes

    for (int i = 0; i < argc - 1; i++)
    {
        int fd[2];
        pipe(fd);
        pid_t childPid;

        if ((childPid = fork()) == -1)
        {
            /* Do some error checking */
            exit(1);
        }

        if (childPid == 0)
        {
            isParent = false;
            dup2(fd[1], 1);
            close(fd[1]);
            close(fd[0]);
            if (argc - 2 == i)
            {
                lastProcess = true;
            }
            command = commands.pop();
        }
        else
        {
            dup2(fd[0], 0);
            close(fd[1]);
            close(fd[0]);
            break;
        }
    }

    // Start piping

    if (!isParent)
    {
        execvp(command[0], command);
        exit(0);
    }
    else
    {
        char buffer[100];
        read(0, buffer, 100);
        printf("%s\n", buffer);
    }

}
