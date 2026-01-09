#include <stdio.h>
#include <errno.h>

int fact(int n) {
    int prod = 1;

    if (n < 0) {
        errno = EINVAL;
        return -1;
    }

    for (int i = n; i > 1; i--)
        prod = prod * i;

    return prod;
}

int main(int argc, char **argv) {
    printf("%d\n", fact(0));
    printf("%d\n", fact(4));
    printf("%d\n", fact(15));
    return 0;
}
