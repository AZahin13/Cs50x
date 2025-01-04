// an array is a data type stored in a contigous manner or back to back 
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// making my own program to implement week2
// Pseudocode:
// get characters from user
// show number of characters from input
// show each char = int

int main(void)
{
    printf("A char = an integer\nand an integer = a char\n");
    printf("let me show you\n");
    printf("\n");
    string x = get_string("Enter a combination of keys on your keyboard:\n");
    printf("Your gave %lu characters \n", strlen(x));

    for (int i = 0, n = strlen(x); i < n; i++)
    {
        printf("charcater %c = %i\n", x[i], x[i]);
    }
    printf("\n");
}
