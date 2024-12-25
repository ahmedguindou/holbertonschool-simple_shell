#include "shell.h"
void parse_line(char *line, char **argv)
{
    char *token;
    token = strtok(line, " \n");
    argv[0] = token;
    argv[1] = NULL;
}
