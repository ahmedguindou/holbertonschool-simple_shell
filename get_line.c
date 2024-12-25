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
