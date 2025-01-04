// a program to capitilise users input
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s;
    printf("This program capitalises your sentence!\n");
    do
    {
        s = get_string("Before: ");
        bool all_letters = true;

        // checks individual char in string for !letters
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            // need both conditions as there are symbols bet z and A in ASCII
            if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] == 32)))
            {
                // only triggers if !letters are found
                all_letters = false;
                // breaks out of the if loop the moment it detects a !letter
                break;
                // otherwise bool stays true and allows program to continue
            }
        }

        if (!all_letters)
        {
            printf("Please input letters only.\n");
        }
        else
        {
            // break here breaks out of the do while loop
            break;
        }
    }
    while (true);

    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            // capitalises lowercases
            // s[i] -= 32;
            printf("%c", s[i] - 32);
        }
        else
        {
            // keeps uppercase letters the same
            // s[i] = s[i];
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
