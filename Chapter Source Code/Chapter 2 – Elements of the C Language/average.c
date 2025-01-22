#include <stdio.h>

int main(int argc, char **argv) {

    int test1, test2, test3, sum;
    double average;

    test1 = 90;
    test2 = 85;
    test3 = 87;

    sum = test1 + test2 + test3;
    average = sum / 3.0;

    printf("The average is %f.\n", average);
}
