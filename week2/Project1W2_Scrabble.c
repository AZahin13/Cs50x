// scrabble game, project 1 of week 2 arrays
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void capitalise(string x);
int score(string x);

int main(void)
{
    // Intro + Receives user1 and user2's input
    printf("Welcome to the Scrable Game! Give me your best word\n");
    printf("Player with most points wins\n");

    // make it uppercase for 1 array
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    // capitalize the string
    capitalise(p1);
    capitalise(p2);
    // printf("%s, %s", p1, p2);

    // calculate total score
    //  for loop where int total then assign value of index to score
    int p1score = score(p1);
    int p2score = score(p2);

    printf("P1 score is %i, P2 score is %i\n", p1score, p2score); //useful for debugging

    // Output of results
    if (p1score > p2score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p2score > p1score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

void capitalise(string x)
{
    int len = strlen(x);
    for (int i = 0; i < len; i++)
    {
        x[i] = toupper(x[i]);
    }
}

int score(string x)
{
    // array to allocate points
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int temp = 0;
    int score = 0;
    int len = strlen(x);
    for (int i = 0; i < len; i++)
    {
        if ((x[i] >= 'A') && (x[i] < 'Z'))
        {
            score += points[x[i] - 65]; // better to use 'A' vs ASCII code
        }
        else
        {
            // ignore
        }
    }
    return score;
}
