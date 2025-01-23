#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char line[255], *cmd = NULL, *p, *c;
    char *brkset = " \t\v\n\r";

    printf("cmd> ");
    while (fgets(line, sizeof line, stdin) != NULL) {

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

        // any args?
        p = p + strspn(p, brkset);
        while ((c = strpbrk(p, brkset)) && c > p) {
            //printf("%p %p\n", p, c);
            int n = strspn(c, brkset);
            *c = '\0';
            printf("arg: %s\n", p);
            p = c + n;
        }

        next:
        free(cmd);
        cmd = NULL;
        printf("cmd> ");
    }

    return 0;
}
