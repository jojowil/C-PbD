#include <stdio.h>

int main(void) {
    int x;

    printf("Enter an integer: ");
    scanf("%d", &x);

    printf("The value %d is ", x);
    if (x < 0)
        printf("Negative.");
    else if (x > 0)
        printf("Positive.");
    else
        printf("Zero.");
    return 0;
}
