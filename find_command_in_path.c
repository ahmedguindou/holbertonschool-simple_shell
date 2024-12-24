#include "shell.h"
#define MAX_PATH_LEN 1024
/**
 * get_full_path - Constructs the full path of a command
 * @path: Current directory from PATH
 * @cmd: Command to locate
 * @full_path: Buffer to store the full path
 * Return: 0 on success, -1 if the path is too long
 */
int get_full_path(const char *path, const char *cmd, char *full_path)
{
if (strlen(path) + strlen(cmd) + 2 > MAX_PATH_LEN)
{
fprintf(stderr, "Path too long\n");
return (-1);
}
strcpy(full_path, path);
strcat(full_path, "/");
strcat(full_path, cmd);
return (0);
}

/**
 * execute_full_path - Executes a command if found
 * @full_path: Full path to the command
 * @argv: Arguments for the command
 * Return: 0 if executed, -1 otherwise
 */
int execute_full_path(const char *full_path, char **argv)
{
if (access(full_path, X_OK) == 0)
{
if (execve(full_path, argv, environ) == -1)
{
perror("execve failed");
return (-1);
}
}
return (-1);
}

/**
 * find_command_in_path - Finds and executes a command in the PATH
 * @cmd: Command to locate
 * @argv: Array of arguments for the command
 * Return: 0 if successful, -1 otherwise
 */
int find_command_in_path(char *cmd, char **argv)
{
char *path_env, *path_copy, *path;
char full_path[MAX_PATH_LEN];

path_env = _getenv("PATH");
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
if (get_full_path(path, cmd, full_path) == 0 &&
execute_full_path(full_path, argv) == 0)
{
free(path_copy);
return (0);
}
path = strtok(NULL, ":");
}
free(path_copy);
return (-1);
}
