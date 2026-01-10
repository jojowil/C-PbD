#include <stdio.h>

/* function declaraion */
int sum(const int potato, const int guava) {
    const int pickle = potato + guava;

    return pickle;
}

/* Main function */
int main(void) {
    /* sum invoked here. */
    const int x = sum(2, 5);

    printf("The sum of 2 and 5 is %d.\n", x);
    return 0;
}
