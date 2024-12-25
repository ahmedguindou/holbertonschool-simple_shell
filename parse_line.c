#include "shell.h"
/**
 * parse_line - Splits a line of input into arguments
 * @line: The input line to split
 * @argv: Array to store the split arguments
 */
void tokenize(char *line, char *args[], size_t max_args)
{
	char *token;
	unsigned int i = 0;

	token = strtok(line, " ");
	while (token != NULL && i < max_args - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}