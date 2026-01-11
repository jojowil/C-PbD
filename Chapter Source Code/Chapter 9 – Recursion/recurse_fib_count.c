#include <stdio.h>
#include <errno.h>

long fibcalls;

int fib(int n) {
    fibcalls++;

    if (n < 0) {
        errno = EINVAL;
        return -1;
    }

    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char **argv) {
    fibcalls = 0;
    printf("%d\n", fib(1));
    printf("fibcalls = %ld\n", fibcalls);

    fibcalls = 0;
    printf("%d\n", fib(4));
    printf("fibcalls = %ld\n", fibcalls);

    fibcalls = 0;
    printf("%d\n", fib(46));
    printf("fibcalls = %ld\n", fibcalls);
    return 0;
}
