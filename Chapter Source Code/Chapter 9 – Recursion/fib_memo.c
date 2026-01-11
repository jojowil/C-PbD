#include <stdio.h>

// globals
long fibcalls;
#define MEMO_SIZE 100
int memo[MEMO_SIZE];

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
    for (int x = 0; x < MEMO_SIZE; x++)
        memo[x] = -1;

    fibcalls = 0;
    printf("%d\n", fib(46));
    printf("fibcalls = %ld\n", fibcalls);
    return 0;
}
