#include "shell.h"

int main() {
char *line = NULL;
char *argv[64];
while (1) {
printf("($) ");
get_line(&line);
parse_line(line, argv);
if (argv[0] != NULL && strcmp(argv[0], "exit") == 0) {
free(line);
exit(0);
}
execute_command(argv);
}
free(line);
return 0;
}
