#include "shell.h"
/**
* get_line - Prints the environment variables to stdout
*
* Description: Iterates through the environment variables
* and prints each one on a new line.
* Return: Always 0 (Success)
*/
int get_line(void)
{
int i = 0;

while (environ[i] != NULL)
{
printf("%s\n", environ[i]);
i++;
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
