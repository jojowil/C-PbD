#include <stdio.h>

int main(int argc, char **argv) {

    int test1, test2, test3;
    double average;

    printf("Enter test 1: ");
    scanf("%d", &test1);

    printf("Enter test 2: ");
    scanf("%d", &test2);

    printf("Enter test 3: ");
    scanf("%d", &test3);

    average = (test1 + test2 + test3) / 3.0;

    printf("The average is %f.\n", average);
}
