#include "shell.h"
extern char **environ;
void execute_command(char **argv)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        return;
    }
    if (pid == 0)
    {
        if (execve(argv[0], argv, environ) == -1)
        {
            perror("execve failed");
        }
    }
    else
    {
        waitpid(pid, NULL, 0);
    }
}
