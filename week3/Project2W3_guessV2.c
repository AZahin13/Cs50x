// random guessing game
// improved version
#include <stdio.h>
#include <stdlib.h> //for rand() LCG algo
#include <time.h> // for time() UNIX epoch secs


int main(void)
{
    printf("This is a number guessing game!\n");

    // seed rand() before program
    // this improves randomness
    srand(time(NULL));

    while(1) // non-zero == true in this case. repeat prog if user wants
    {
        // prompt user + input for guess
        // declare variable
        int guess = 0;
        do
        {
            printf("Guess from 1 - 9: ");
            scanf("%i", &guess);
        } while (guess < 1 || guess > 9);

        // get a random # from 1-9
        int randnum = ((rand()%9) + 1);

        // check guess
        if (guess == randnum)
        {
            // winning message
            printf("The random number was %i, you guessed %i\n", randnum, guess);
            printf("You win!\n");
        }
        else
        {
            // losing message
            printf("The random number was %i, you guessed %i\n", randnum, guess);
            printf("You lose :(\n");
        }

        // allow user to run program again
        char again = 'y';
        printf("Would you like to play again? y/n ");

        // scanf needs an address don't forget
        // leave space before format code, as newlines from prev input
        // might still be in the input buffer
        scanf(" %c", &again);

        if (!(again == 'y' || again == 'Y'))
        {
            // leave the loop and end the program
            printf("Thanks for playing! \n");
            return 0;
        }
    }
}
