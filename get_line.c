#include "shell.h"
int get_line(char **line)
{
    size_t bufsize = 1024;
    *line = (char *)malloc(bufsize * sizeof(char));
    if (*line == NULL)
    {
        perror("malloc failed");
        exit(1);
    }
    if (getline(line, &bufsize, stdin) == -1)
    {
        printf("\nExiting...\n");
        free(*line);
        exit(0);
    }
    return 0;  
}
