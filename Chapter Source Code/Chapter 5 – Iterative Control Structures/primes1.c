#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool prime;

    for (int number = 2; number <= 100; number++) {
        if (number % 2 != 0)
            prime = true;
        else
            prime = false;

        for (int range = 3; prime && range < number; range = range + 2) {
            if (number % range == 0)
                prime = false;
        }

        if (prime)
            printf("%d\n", number);
    }
    return 0;
}
