#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    int r;

    srand(37);
    r = rand();

    printf("r is %d\n\n", r);
    printf("d4  = %d\n", r % 4 + 1);
    printf("d6  = %d\n", r % 6 + 1);
    printf("d8  = %d\n", r % 8 + 1);
    printf("d10 = %d\n", r % 10 + 1);
    printf("d12 = %d\n", r % 12 + 1);
    printf("d20 = %d\n", r % 20 + 1);
}
