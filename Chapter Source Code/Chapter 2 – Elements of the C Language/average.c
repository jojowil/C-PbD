#include <stdio.h>

int main(int argc, char **argv) {
    const int test1 = 90;
    const int test2 = 85;
    const int test3 = 87;

    const int sum = test1 + test2 + test3;
    const double average = sum / 3.0;

    printf("The average is %f.\n", average);
}
