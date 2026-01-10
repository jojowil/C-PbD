#include <stdio.h>
#include <stdbool.h>

int main(void) {
    for (int number = 3; number <= 97; number = number + 2) {
        bool prime = true;

        for (int range = 3; prime && range < number; range = range + 2) {
            if (number % range == 0)
                prime = false;
        }

        if (prime)
            printf("%d\n", number);
    }
    return 0;
}
