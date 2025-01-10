// a program to demonstrate strings
// are not strings
// also implementing memory allocation

#include <cs50.h> // getting rid of training soon
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // includes malloc and sizeof

// a program to transfer the values of 1 array to another

int main(void)
{
    // obtain user input
    string s = get_string("Lowercase String A: ");
    printf("\n");

    // code defensively
    // checking if value of string is empty
    if ((!*s) || *s == ' ')
    {
        printf("Please enter a lowercase string before running\n");
        return 1;
    }

    // we now know that strings are pointers
    // pointers to the first char to be exact
    // make a new pointer aka "a string"

    // how do I transfer s to t?

    // 1st allocate some memory starting from t
    // strlen only measure the chars input
    // +1 to include NULL terminator
    int size = (strlen(s) * sizeof(char)) + 1;

    // assign the pointer to a memory location
    char *t = malloc(size);

    // Show that diff strings have diff address
    printf("Different addreses:\n");
    printf("String A address: %p\n", s);
    printf("String B address: %p\n", t);
    printf("\n");

    // 2nd copy
    // can use stringcpy(destination, source);
    // but that's lame
    // funny because strlens here is enough since
    // array notation starts at 0
    // 1(aka 0) + strlen = strlen + 1
    // means no need to add space for null term
    // I mean i < n + 1 is also viable, alas
    // i <= n = strlen + 1
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // capitalise to show difference
    t[0] = toupper(t[0]);

    // output difference
    printf("Tada!\n");
    printf("String A: %s\n", s);
    printf("Copied String B: %s\n", t);

    // always free your memory!
    // avoid memory leaks!
    // use valgrind to check for memory leaks!
    free(t);
    return 0;
}
