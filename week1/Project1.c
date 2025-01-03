// my first attempt at the mario project
#include <cs50.h>
#include <stdio.h>

// say this is mario tower builder
// ask for level of tower
// print out # based on level
// for every additional level +1 #
// was stuck on this for some time ngl
// but solving it was so rewarding and helped in understanding
// for loops!

int main(void)
{
    int n = 0;
    do
    {
        n = get_int("How many levels on your tower? only +integers please\n");

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < i; j++)
            {
                printf("#");
            }
            printf("  ");
            for (int j = 0; j < i; j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    while (n < 1);
    return 0;
}
