#include <stdio.h>

// prototypes
int fib(int n);
int fib2(int n, int p, int c);

// global
long fibcalls;

int fib(int n) {
    return fib2(n, -1, 1);
}

int fib2(int n, int p, int c) {
    fibcalls++;
    if (n == 0)
        return p + c;
    return fib2(n - 1, c, p + c);
}

int main(void) {
    fibcalls = 0;
    printf("%d\n", fib(46));
    printf("fibcalls = %ld\n", fibcalls);
    return 0;
}
