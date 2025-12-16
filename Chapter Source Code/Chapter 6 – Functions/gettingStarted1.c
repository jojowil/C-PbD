#include <stdio.h>

/* function declaraion */
int sum(int a, int b) {

    int t;

    t = a + b;

    return t;
}

/* Main function */
int main(int argc, char** argv) {

    int x;

    /* sum invoked here. */
    x = sum(2,5);

    printf("The sum of 2 and 5 is %d.\n", x);
}
