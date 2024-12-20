#include "shell.h"

void get_line(char **line)
{
size_t bufsize = 1024;
*line = (char *)malloc(bufsize * sizeof(char))
printf("$ ");
if (getline(line, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
printf("\nExiting...\n");
exit (0);
}
perror("getline failed");
exit (1);
}
}
