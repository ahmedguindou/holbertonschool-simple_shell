#include "shell.h"
/**
* parse_line - Parses the user input into tokens
* @line: The input string from the user
*
* Description: Splits the input line into tokens,
* processes commands like "exit" and "env",
* and handles execution or error reporting.
*/
void parse_line(char *line)
{
int i = 0;
char *tokens[1024] = {NULL};
char *token = NULL;

token = strtok(line, " \t");
while (token != NULL)
{
if (strlen(token) > 0)
{
tokens[i] = token;
i++;
}
token = strtok(NULL, " \t");
}
if (tokens[0] == NULL)
{
return;
}
if (strcmp(tokens[0], "exit") == 0 && tokens[1] == NULL)
{
free(tokens[0]);
exit(0);
}
if (strcmp(tokens[0], "env") == 0)
{
get_line();
return;
}
token = strdup(tokens[0]);
tokens[0] = get_path(token);
if (tokens[0] != NULL)
{
free(token);
execute_command(tokens, line);
free(tokens[0]);
return;
}
fprintf(stderr, " %s: not found\n", token);
free(token);
}
