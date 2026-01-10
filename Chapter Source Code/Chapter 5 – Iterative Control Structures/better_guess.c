#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int randomNumber, guess, guessLimit = 5;
    bool found;

    srand(time(NULL));

    // random number between 1 and 20
    randomNumber = rand() % 20 + 1;

    printf("I'm thinking of a number between 1 and 20.\n");

    found = false;
    while (!found && guessLimit > 0) {
        printf("You have %d guesses remaining.\n", guessLimit);
        printf("Guess the value between 1 and 20: ");
        scanf("%d", &guess);
        guessLimit--;

        if (guess == randomNumber)
            found = true;
        else
            printf("It's not %d.\n", guess);
    }

    if (found)
        printf("\nYou got it!\n");
    else
        printf("\nThe number was %d.\n", randomNumber);
}
