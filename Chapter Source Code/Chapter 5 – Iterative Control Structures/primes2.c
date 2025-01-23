#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int number, range;
    bool prime;

    for (number = 3; number <= 97; number = number + 2) {
        prime = true;

        for (range = 3; prime && range < number; range = range + 2) {
            if (number % range == 0)
                prime = false;
        }

        if (prime)
            printf("%d\n", number);
    }
}
