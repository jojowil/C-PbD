#include <stdio.h>
#include <errno.h>

int fib(int n) {
    if (n < 0) {
        errno = EINVAL;
        return -1;
    }

    int previous = -1;
    int current = 1;

    for (int i = 0; i <= n; i++) {
        int sum = current + previous;
        previous = current;
        current = sum;
    }
    return current;
}

int main(void) {
    printf("%d\n", fib(46));
    return 0;
}
