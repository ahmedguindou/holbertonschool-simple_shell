#include "shell.h"
#define MAX_PATH_LEN 1024
extern char **environ;

int find_command_in_path(char *cmd, char **argv) {
char *path_env = _getenv("PATH");
char *path_copy;
char *path;
char full_path[MAX_PATH_LEN];
if (!path_env) {
fprintf(stderr, "PATH not found\n");
return -1;
}
path_copy = strdup(path_env);
if (!path_copy) {
perror("strdup failed");
return -1;
}
path = strtok(path_copy, ":");
while (path != NULL) {
snprintf(full_path, sizeof(full_path), "%s/%s", path, cmd);
if (access(full_path, X_OK) == 0) {
free(path_copy);
if (execve(full_path, argv, environ) == -1) {
perror("execve failed");
return -1;
}
}
path = strtok(NULL, ":");
}
free(path_copy);
return -1;
}
