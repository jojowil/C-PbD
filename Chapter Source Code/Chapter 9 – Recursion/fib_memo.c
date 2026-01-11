#include <stdio.h>

// globals
long fibcalls;
#define MEMOSIZE 100
int memo[MEMOSIZE];

int fib(int n) {
    fibcalls++;

    if (memo[n] != -1)
        return memo[n];

    if (n == 0 || n == 1)
        return n;

    int sum = fib(n - 1) + fib(n - 2);
    memo[n] = sum;
    return sum;
}

int main(void) {
    // allocate array and set start values to -1.
    for (int x = 0; x < MEMOSIZE; x++)
        memo[x] = -1;

    fibcalls = 0;
    printf("%d\n", fib(46));
    printf("fibcalls = %ld\n", fibcalls);
    return 0;
}
