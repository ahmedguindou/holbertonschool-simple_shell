#include "shell.h"
/**
 * get_line - Reads a line of input from stdin
 * @line: Pointer to the buffer to store the input
 */
int _printenv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}