#include "shell.h"

extern char **environ;
char *_getenv(const char *name)
{
size_t name_len = strlen(name);
for (int i = 0; environ[i] != NULL; i++)
{
if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
{
return &environ[i][name_len + 1];
}
}
return NULL;
}
