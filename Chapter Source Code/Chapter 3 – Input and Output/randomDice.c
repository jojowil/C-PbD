#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    int r;

    srand(time(NULL));
    r = rand();

    printf("r is %d\n\n", r);
    printf("%d\n", r % 4 + 1);
    printf("%d\n", r % 6 + 1);
    printf("%d\n", r % 8 + 1);
    printf("%d\n", r % 10 + 1);
    printf("%d\n", r % 12 + 1);
    printf("%d\n", r % 20 + 1);
}
