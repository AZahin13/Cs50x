#include <cs50.h>
#include <stdio.h>

// test mario stair maker using abstractions instead
// looking back, I think V1 is cleaner though both programmed scored full scores on check50
// prototypes
void rows(int row_number);
void spaces(int spaces);

// variables
int levels;
int i;

int main(void)
{
    do
    {
        // obtains user input on # of levels
        levels = get_int("How many levels?\n");

        // outer loop that runs based on number of levels
        for (i = 1; i <= levels; i++)
        {
            spaces(levels);
            rows(levels);
            printf(" ");
            rows(levels);
            printf("\n");
        }
    }
    while (levels < 0);
}

// inner loop that prints the rows
void rows(int row_number)
{
    for (int j = 0; j < i; j++)
    {
        printf("#");
    }
}

// inner loop that prints spaces
void spaces(int spaces)
{
    for (int j = 0; j < levels - i; j++)
    {
        printf(" ");
    }
}
