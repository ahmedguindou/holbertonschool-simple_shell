#include "shell.h"

void parse_line(char *line, char **argv) {
char *token;
int i = 0;
token = strtok(line, " ");
while (token != NULL) {
argv[i] = token;
i++;
token = strtok(NULL, " ");
}
argv[i] = NULL;
}