#include "shell.h"
/**
 * _getenv - Retrieves the value of an environment variable
 * @name: Name of the environment variable to find
 * Return: Pointer to the value of
 * the environment variable, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *token;
	char *copy_env = NULL;
	char *copy_path = NULL;

	while (environ[i] != NULL)
	{
		copy_env = strdup(environ[i]);
		token = strtok(copy_env, "=");
		if (token == NULL)
		{
			free(copy_env);
			return (NULL);
		}
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			copy_path = strdup(token);
			free(copy_env);
			return (copy_path);
		}
		i++;
		free(copy_env);
	}
	return (NULL);
}