#include "shell.h"
/**
 * get_line - Reads a line of input from stdin
 * @line: Pointer to the buffer to store the input
 */
int get_line(char **line)
{
size_t bufsize = 1024;
ssize_t read_len;
*line = malloc(bufsize);
if (*line == NULL)
{
perror("malloc failed");
return (-1);
}
read_len = getline(line, &bufsize, stdin);
if (read_len == -1)
{
printf("\nExiting...\n");
return (-1);
}
(*line)[read_len - 1] = ((*line)[read_len - 1] == '\n') ? '\0' : (*line)[read_len - 1];
return (0);
}
