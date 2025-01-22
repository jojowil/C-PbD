#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long a;
    char buf[300];
    char *p;

    printf("enter a number: ");
    fgets(buf, sizeof buf, stdin);

    // have some input, convert it to integer:
    a = strtol(buf, &p, 10);

    printf("You entered %ld\n", a);
    return 0;
}
