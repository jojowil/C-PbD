#include <stdio.h>

int main(int argc, char *argv[]) {
    int sum = 0, count = 0;
    int value;
    double avg;

    printf("Enter a number (CTRL-D to end): ");
    while (scanf("%d", &value) != EOF) {
        sum = sum + value;
        count++;
        printf("Enter a number (CTRL-D to end): ");
    }

    avg = sum / (double) count;

    printf("\nThe sum is %d.\n", sum);
    printf("The average is %f.\n", avg);
}
