#include "shell.h"
/**
 * _getenv - Retrieves the value of an environment variable
 * @name: Name of the environment variable to find
 * Return: Pointer to the value of
 * the environment variable, or NULL if not found
 */
extern char **environ;
char *_getenv(const char *name)
{
int i = 0;
size_t name_len = strlen(name);
for (i = 0; environ[i] != NULL; i++)
{
if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
{
return (&environ[i][name_len + 1]);
}
}
return (NULL);
}
