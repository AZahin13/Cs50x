// random guessing game
// needed a small win so created this random guessing game!
// learnt about PRNG and LCG algorithm in the process
// PRNG : Pseudo-Random Number Generator
// LCG algorithm: Linear Congruential Generator
// also about the eventual end of the UNIX epoch
// iz gud
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool play = true; //it's not necessary to include a global variable
// you can run a do while loop with the variable inside of main
// by using a while loop and just breaking the loop if yes

int main(void)
{
    printf("This is a number guessing game!\n");
    do
    {
        int guess = get_int("Guess from 1 - 9: "); // not coding defensively, pre-empt invalid input
        srand(time(NULL)); // Seed outside the loop, seeding inside reduces randomness
        int randnum = (rand()%10);

        if (randnum == 0){randnum = 1;} // instead of using if statements just change the randrange
        if (guess == randnum) // not coding defensively, pre-empt invalid input
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
