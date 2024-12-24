#include "shell.h"
/**
 * get_line - Reads a line of input from stdin
 * @line: Pointer to the buffer to store the input
 */
void get_line(char **line) {
size_t bufsize = 1024;
size_t len;
*line = (char *)malloc(bufsize * sizeof(char));
printf("$ ");
if (getline(line, &bufsize, stdin) == -1) {
if (feof(stdin)) {
printf("\nExiting...\n");
exit(0);
}
perror("getline failed");
exit(1);
}
len = strlen(*line);
if ((*line)[len - 1] == '\n') {
(*line)[len - 1] = '\0';
}
}
