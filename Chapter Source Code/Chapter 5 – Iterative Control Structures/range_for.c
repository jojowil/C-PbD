#include <stdio.h>

int main(void) {
    int sum = 0;
    int x, value;

    for (x = 1; x <= 3; x++) {
        printf("Enter value #%d: ", x);
        scanf("%d", &value);
        sum = sum + value;
    }

    double avg = sum / 3.0;

    printf("The sum is %d.\n", sum);
    printf("The average is %f.\n", avg);
    return 0;
}
