#include "shell.h"
/**
* execute_command - Forks a child process and executes a command
* @argv: Array of arguments for the command
* @line: Pointer to the input line (for cleanup purposes)
* Description: This function checks if the command is executable,
* forks a child process to execute it, and handles cleanup
* and error reporting based on the child process's exit status.
*/
void execute_command(char *argv[], char *line)
{
int status;
pid_t child;
if (access(argv[0], X_OK) != 0)
{
fprintf(stderr, "%s: not found\n", argv[0]);
free(argv[0]);
exit(127);
}
child = fork();
if (child == -1)
{
perror("Fail Fork");
exit(0);
}
else if (child == 0)
{
execve(argv[0], argv, environ);
free(argv[0]);
exit(0);
}
else
{
wait(&status);
if (status != 0)
{
free(argv[0]);
free(line);
exit(2);
}
}
}
