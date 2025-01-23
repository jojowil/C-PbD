#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARGMAX 10
#define LINEMAX 255

int main(int argc, char *argv[]) {

    char line[LINEMAX], *p, *c;
    char *brkset = " \t\v\n\r";
    int len = 0;
    char *parts[ARGMAX];

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
        p = line + strspn(line, brkset);
        if (!*p)
            goto next;

        while ((c = strpbrk(p, brkset)) && c > p) {
            //printf("%p %p\n", p, c);
            int n = strspn(c, brkset);
            if (len == ARGMAX) {
                fprintf(stderr, "Too many parts. Max is %d.\n", ARGMAX);
                goto cleanup;
            }
            parts[len++] = strndup(p, c - p);
            p = c + n;
        }

        printf("There are %d of %d parts\n", len, ARGMAX);
        for (int x = 0; x < len; x++)
            printf("%s\n", parts[x]);

        cleanup:
        for (int x = 0; x < len; x++)
            free(parts[x]);

        len = 0;

        next:
        printf("cmd> ");
    }

    return 0;
}
