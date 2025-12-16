#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printArray(int a[], int l) {
    int x;
    for (x = 0; x < l; x++)
        printf("Value at index %d is %d\n", x, a[x]);
}

int main(int argc, char *argv[]) {
    int array[5];
    int len, x, sum=0;
    double avg;

    len = sizeof array / sizeof array[0];

    // initialize the array to random numbers.
    for (x = 0; x < len; x++)
        array[x] = rand() % 100 + 1;

    // display array contents.
    printArray(array, len);

    // read data into array.
    for (x = 0; x < len; x++) {
        printf("Enter value for array[%d]: ", x);
        scanf(" %d", &array[x]);
    }

    // display array contents.
    printArray(array, len);

    // sum the array and calculate the average.
    for (x = 0; x < len; x++)
        sum = sum + array[x];
    avg = (double)sum / len;

    printf("The average of the entered values is %.2f\n", avg);
}
