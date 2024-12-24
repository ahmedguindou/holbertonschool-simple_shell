#include "shell.h"
/**
 * get_line - Reads a line of input from stdin
 * @line: Pointer to the buffer to store the input
 */
void get_line(char **line)
{
size_t bufsize = 1024;
size_t len;
*line = (char *)malloc(bufsize * sizeof(char));
if (*line == NULL)
{
perror("malloc failed");
exit(1);
}
if (getline(line, &bufsize, stdin) == -1)
{
printf("\nExiting...\n");
free(*line);
exit(0);
}
len = strlen(*line);
if ((*line)[len - 1] == '\n')
{
(*line)[len - 1] = '\0';
}
}
