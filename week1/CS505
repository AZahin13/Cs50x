// this is a prototype
// it enables the main program int main() to be above
// the abstraction
// This project I attempted to get the program to repeat the
// variable if the int given is <1 before referring to CS50
// I was recommended the implementation of labels by chatGPT
// will attempt the cs50 way in my next file

#include <cs50.h>
#include <stdio.h>
#include <unistd.h>

void meow(int n);

int main(void)
{
    printf("   /\\_/\\\n");
    printf("  ( o.o )\n");
    printf("   > ^ <\n");
    sleep(1);
    printf("This is Hamilton the cat!\n");
start:
{
    int n = get_int("How many times will you pet the cat?\n");
    if (n < 0)
    {
        printf("How do you negatively pet your cat!!??\n");
        sleep(1);
        printf("Give me a positive # of pets!\n");
        sleep(1);
        goto start;
    }
    else if (n == 0)
    {
        printf("We don't like you either!\n");
    }
    else
    {
        meow(n);
    }
    // the n above is not the same as int n at line 29 or 8
    // this is because n has to be within context{} to be related
}
}

// making an abstraction of meow akin to scratch
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow!\n");
    }
}
