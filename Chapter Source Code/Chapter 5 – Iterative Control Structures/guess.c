#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int guess;

    srand(time(NULL));
    // random number between 1 and 20
    int random_number = rand() % 20 + 1;

    printf("I'm thinking of a number between 1 and 20.\n");

    bool found = false;
    while (!found) {
        printf("Guess the value between 1 and 20: ");
        scanf("%d", &guess);

        if (guess == random_number)
            found = true;
        else
            printf("It's not %d.\n", guess);
    }

    printf("\nYou got it!\n");
    return 0;
}
