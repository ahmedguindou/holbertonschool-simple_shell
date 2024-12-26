#include "shell.h"
/**
* get_path - Finds the full path of a command
* @command: The command to find in the PATH
* Description: This function checks if the command contains a '/'.
* If it does, the command is returned directly. Otherwise, it searches
* the PATH environment variable to find the command's full path.
* Return: Pointer to the full path of the command, or NULL if not found
*/
char *get_path(char *command)
{
char *path_copy = NULL;
char *full_path = NULL;
char *token = NULL;

if (strchr(command, '/') != NULL)
{
return (strdup(command));
}

path_copy = _getenv("PATH");
token = strtok(path_copy, ":");

while (token != NULL)
{
full_path = malloc(strlen(token) + strlen(command) + 2);
if (full_path == NULL)
{
perror("Malloc is NULL");
return (NULL);
}

sprintf(full_path, "%s/%s", token, command);

if (access(full_path, X_OK) == 0)
{
free(path_copy);
return (full_path);
}

free(full_path);
token = strtok(NULL, ":");
}
free(path_copy);
return (NULL);
}
