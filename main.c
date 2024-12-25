#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> 

extern char **environ; 

#define MAX_CMD_LENGTH 1024

/**
 * main - Entry point of the shell program
 * Return: 0 on success, or an error code on failure.
 */
int main(void)
{
    char *cmd = NULL;
    size_t len = 0;
    ssize_t nread;
    char *args[] = {NULL, NULL};  /* Command and its argument (for now only one command) */

    while (1)
    {
        /* Display prompt */
        printf("$ ");
        
        /* Get the command from user */
        nread = getline(&cmd, &len, stdin);
        if (nread == -1)
        {
            /* Handle EOF (Ctrl+D) */
            free(cmd);
            printf("\n");
            exit(0);
        }

        /* Remove newline character */
        cmd[strcspn(cmd, "\n")] = 0;

        if (cmd[0] == '\0')  /* Ignore empty lines */
            continue;

        /* Prepare the arguments array */
        args[0] = cmd;

        /* Execute the command using execve */
        if (fork() == 0)
        {
            if (execve(cmd, args, environ) == -1)
            {
                /* Handle command not found */
                perror("Error");
                exit(1);
            }
        }
        else
        {
            /* Parent waits for the child process to finish */
            wait(NULL);
        }
    }

    free(cmd);
    return 0;
}
