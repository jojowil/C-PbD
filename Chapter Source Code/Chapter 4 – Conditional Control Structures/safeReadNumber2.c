#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void) {
    char buf[300];
    char *p;

    printf("enter a number: ");
    if (!fgets(buf, sizeof buf, stdin)) {
        // reading input failed, give up:
        return 1;
    }

    // have some input, convert it to integer:
    errno = 0;
    const long a = strtol(buf, &p, 10);

    // *p can be '\0' or '\n', but p cannot be buf.
    int success = ((!*p || *p == '\n') && p != buf && !errno);
    if (errno)
        perror("strtol");
    else if (!success)
        printf("You did not enter a valid number.\n");
    else
        printf("You entered %ld\n", a);

    return 0;
}
