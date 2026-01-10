#include <stdio.h>

int main(int argc, char *argv[]) {
    int sum = 0;
    int x, value;
    double avg;

    for (x = 1; x <= 3; x++) {
        printf("Enter value #%d: ", x);
        scanf("%d", &value);
        sum = sum + value;
    }

    avg = sum / 3.0;

    printf("The sum is %d.\n", sum);
    printf("The average is %f.\n", avg);
}
