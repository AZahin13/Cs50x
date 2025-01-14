// random guessing game
// needed a small win so created this random guessing game!
// iz gud
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool play = true;

int main(void)
{
    printf("This is a number guessing game!\n");
    do
    {
        int guess = get_int("Guess from 1 - 9: ");
        srand(time(NULL));
        int randnum = (rand()%10);

        if (randnum == 0){randnum = 1;}
        if (guess == randnum)
        {
            printf("The random number was %i, you guessed %i\n", randnum, guess);
            printf("You win!\n");
        }
        else
        {
            printf("The random number was %i, you guessed %i\n", randnum, guess);
            printf("You lose :(\n");
        }

        char again = get_char("Play again? Y/N: ");
        if (again == 'y' || again == 'Y')
        {
            play = true;
        }
        else
        {
            printf("Thanks for playing \n");
            return 0;
        }
    }
    while (play == true);
}
