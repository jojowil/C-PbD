#include <stdio.h>

int main(void) {
    int sum = 0;
    int value;

    int x = 1;   //initialization
    while (x <= 3) {  //condition
        printf("Enter value #%d: ", x);
        scanf("%d", &value);
        sum = sum + value;
        x++;   //update
    }

    double avg = sum / 3.0;

    printf("The sum is %d.\n", sum);
    printf("The average is %f.\n", avg);
    return 0;
}
