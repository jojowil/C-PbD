#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(void) {
    int guess, guess_limit = 5;

    srand(time(NULL));

    // random number between 1 and 20
    int random_number = rand() % 20 + 1;

    printf("I'm thinking of a number between 1 and 20.\n");

    bool found = false;
    while (!found && guess_limit > 0) {
        printf("You have %d guesses remaining.\n", guess_limit);
        printf("Guess the value between 1 and 20: ");
        scanf("%d", &guess);
        guess_limit--;

        if (guess == random_number)
            found = true;
        else
            printf("It's not %d.\n", guess);
    }

    if (found)
        printf("\nYou got it!\n");
    else
        printf("\nThe number was %d.\n", random_number);
    return 0;
}
