#define _GNU_SOURCE
#include "shell.h"
/**
* main - Entry point for the shell program
*
* Return: Always 0 (Success)
*/
int main(void)
{
char *line = NULL;

while (1)
{
if (isatty(STDIN_FILENO) == 1)
{
printf("($) ");
fflush(stdout);
}

line = read_line();
parse_line(line);
free(line);
}
return (0);
}

/**
* read_line - Reads user input from the standard input
*
* Return: Pointer to the input string
*/
char *read_line(void)
{
char *line = NULL;
ssize_t bytes_read;
size_t buff_size = 0;

bytes_read = getline(&line, &buff_size, stdin);
if (bytes_read == EOF)
{
free(line);
exit(0);
}
if (bytes_read > 0 && line[bytes_read - 1] == '\n')
line[bytes_read - 1] = '\0';
return (line);
}
