#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int get_line(char **line);
void parse_line(char *line, char **argv);
char *_getenv(const char *name);
int find_command_in_path(char *cmd, char **argv);
void execute_command(char **argv);
#endif
