#include <stdio.h>
#include <errno.h>

int fact(int n) {
    if (n < 0) {
        errno = EINVAL;
        return -1;
    }

    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main(void) {
    printf("%d\n", fact(0));
    printf("%d\n", fact(4));
    printf("%d\n", fact(15));
    return 0;
}
