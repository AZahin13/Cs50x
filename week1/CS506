// application of modularity
// sleep deprived making this one, programming functions really messed with my head
#include <cs50.h>
#include <stdio.h>

int get_cheer_number(void);
void cheer(int x);

int main(void)
{
    int times = get_cheer_number();
    cheer(times);
}

// function to retrieve n
int get_cheer_number(void)
{
    int n;
    do
    {
        n = get_int("How many times would you like to cheer?\n");
    }
    while (n < 1);
    return n;
}

// abstraction to print cheer
void cheer(int x)
{
    for (int i = 0; i < x; i++) // don't confuse for LOOPS and if statements
    {
        printf("cheer!\n");
    }
}
