#include "shell.h"
/**
 * parse_line - Splits a line of input into arguments
 * @line: The input line to split
 * @argv: Array to store the split arguments
 */
void parse_line(char *line, char **argv)
{
char *token;
int i = 0;
token = strtok(line, " ");
while (token != NULL)
{
argv[i] = token;
i++;
token = strtok(NULL, " ");
}
argv[i] = NULL;
}
