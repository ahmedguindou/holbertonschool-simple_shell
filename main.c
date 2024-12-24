#include "shell.h"
/**
 * main - Entry point for the shell program
 * Return: 0 on success
 */
int main(void)
{
char *line = NULL;
char *argv[64];
while (1)
{
if (isatty(fileno(stdin)))
printf("($) ");
get_line(&line);
parse_line(line, argv);
if (argv[0] != NULL && strcmp(argv[0], "exit") == 0)
{
free(line);
exit(0);
}
execute_command(argv);
free(line);
line = NULL;
}
return (0);
}
