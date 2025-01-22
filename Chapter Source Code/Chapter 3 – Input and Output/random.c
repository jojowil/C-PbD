#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    int r;

    srand(time(NULL));
    r = rand() % 6 + 1;

    printf("r = %d\n", r);
    printf("RAND_MAX = %d\n", RAND_MAX);
}
