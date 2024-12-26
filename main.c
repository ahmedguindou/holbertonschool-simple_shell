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
