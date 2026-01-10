#include <stdio.h>

int main(int argc, char *argv[]) {
    int sum = 0;
    int x, value;
    double avg;

    x = 1;   //initialization
    while (x <= 3) {  //condition
        printf("Enter value #%d: ", x);
        scanf("%d", &value);
        sum = sum + value;
        x++;   //update
    }

    avg = sum / 3.0;

    printf("The sum is %d.\n", sum);
    printf("The average is %f.\n", avg);
}
