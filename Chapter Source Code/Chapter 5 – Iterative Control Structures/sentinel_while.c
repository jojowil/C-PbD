#include <stdio.h>

int main(int argc, char *argv[]) {
    int sum = 0, count = 0;
    int value;
    double avg;

    printf("Enter integers (-1 to end): ");
    scanf("%d", &value);    //initialization
    while (value != -1) { //condition
        sum = sum + value;
        count++;
        printf("Enter integers (-1 to end): ");
        scanf("%d", &value);  //update
    }

    avg = sum / (double) count;

    printf("The sum is %d.\n", sum);
    printf("The average is %f.\n", avg);
}
