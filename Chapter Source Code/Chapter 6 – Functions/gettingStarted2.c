#include <stdio.h>

/* function declaraion */
int sum(int potato, int guava) {

    int pickle;

    pickle = potato + guava;

    return pickle;
}

/* Main function */
int main(int argc, char** argv) {

    int x;

    /* sum invoked here. */
    x = sum(2,5);

    printf("The sum of 2 and 5 is %d.\n", x);
}
