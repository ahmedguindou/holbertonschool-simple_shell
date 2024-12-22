#include "shell.h"
extern char **environ;

void execute_command(char **argv) {
pid_t pid = fork();
if (pid == -1) {
perror("fork failed");
return;
}
if (pid == 0) {
char *cmd = argv[0];
if (cmd[0] == '/' || cmd[0] == '.') {
if (execve(cmd, argv, environ) == -1) {
perror("execve failed");
exit(1);
}
} else {
if (find_command_in_path(cmd, argv) == -1) {
fprintf(stderr, "Command not found: %s\n", cmd);
exit(1);
}
}
} else {
waitpid(pid, NULL, 0);
}
}
