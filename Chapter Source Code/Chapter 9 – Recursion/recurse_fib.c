#include <stdio.h>
#include <errno.h>

int fib(int n) {
    if (n < 0) {
        errno = EINVAL;
        return -1;
    }

    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main(void) {
    printf("%d\n", fib(46));
    return 0;
}
