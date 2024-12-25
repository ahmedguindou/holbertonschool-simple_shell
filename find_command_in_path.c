#include "shell.h"
#define MAX_PATH_LEN 1024
extern char **environ;
/**
 * find_command_in_path - Finds and executes a command in the PATH
 * @cmd: Command to locate
 * @argv: Array of arguments for the command
 * Return: 0 if successful, -1 otherwise
 */
int find_command_in_path(char *cmd, char **argv)
{
char *path_env = _getenv("PATH");
char *path_copy;
char *path;
char full_path[MAX_PATH_LEN];
if (!path_env)
{
fprintf(stderr, "PATH not found\n");
return (-1);
}
path_copy = strdup(path_env);
if (!path_copy)
{
perror("strdup failed");
return (-1);
}
path = strtok(path_copy, ":");
while (path != NULL)
{
full_path[0] = '\0';
if (strlen(path) + strlen(cmd) + 2 > MAX_PATH_LEN)
{
fprintf(stderr, "Path too long\n");
free(path_copy);
return (-1);
}
strcpy(full_path, path);
strcat(full_path, "/");
strcat(full_path, cmd);
if (access(full_path, X_OK) == 0)
{
free(path_copy);
if (execve(full_path, argv, environ) == -1)
{
perror("execve failed");
return (-1);
}
}
path = strtok(NULL, ":");
}
free(path_copy);
return (-1);
}
