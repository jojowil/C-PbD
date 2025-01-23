#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int number, range;
    bool prime;

    for (number = 2; number <= 100; number++) {
        if (number % 2 != 0)
            prime = true;
        else
            prime = false;

        for (range = 3; prime && range < number; range = range + 2) {
            if (number % range == 0)
                prime = false;
        }

        if (prime)
            printf("%d\n", number);
    }
}
