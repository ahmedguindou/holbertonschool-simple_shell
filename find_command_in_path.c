#include "shell.h"

int find_command_in_path(char *cmd, char **argv)
{
char *path_env = _getenv("PATH");
char *path = strtok(path_env, ":");
char full_path[MAX_PATH_LEN];
while (path != NULL)
{
strcpy(full_path, path);
strcat(full_path, "/");
strcat(full_path, cmd);
if (access(full_path, X_OK) == 0)
{
if (execve(full_path, argv, NULL) == -1)
{
perror("execve failed");
return -1;
}
}
path = strtok(NULL, ":");
}
return -1;
}
