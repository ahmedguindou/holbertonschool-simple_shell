#include "shell.h"

/**
 * main - Entry point for the shell program
 * Return: 0 on success
 */
int main(void)
{
    char *line = NULL;
    char *argv[2];

    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("($) ");
        if (get_line(&line) == -1)
        {
            free(line);
            exit(0);
        }
        parse_line(line, argv);
        if (argv[0] != NULL && strcmp(argv[0], "exit") == 0)
        {
            free(line);
            exit(0);
        }
        if (argv[0] != NULL)
        {
            execute_command(argv); 
        }
        free(line);
    }

    return (0);
}
