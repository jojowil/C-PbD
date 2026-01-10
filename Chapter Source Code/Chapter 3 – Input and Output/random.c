#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    const int r = rand() % 6 + 1;

    printf("r = %d\n", r);
    printf("RAND_MAX = %d\n", RAND_MAX);
    return 0;
}
