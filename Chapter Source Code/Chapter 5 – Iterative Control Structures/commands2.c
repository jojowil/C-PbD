#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char line[255], *cmd = NULL, *p, *c;

    printf("cmd> ");
    while (fgets(line, sizeof line, stdin) != NULL) {
        char *brkset = " \t\v\n\r";

        // too long?
        if (!(strchr(line, '\n'))) {
            fputs("\nCommand line too long.\n\n", stderr);
            do {
                fgets(line, sizeof line, stdin);
            } while (!(strchr(line, '\n')));
            goto next;
        }

        // anything here?
        c = line + strspn(line, brkset);
        if (!*c)
            goto next;

        // find command
        p = strpbrk(c, brkset);
        cmd = strndup(c, p - c);

        printf("The command is: %s\n", cmd);

        next:
        free(cmd);
        cmd = NULL;
        printf("cmd> ");
    }

    return 0;
}
