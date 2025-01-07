// using command line arguments
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // get user's input from command line
    string letters = argv[1];

    // ask if no second arg
    if (argc != 2)
    {
        printf("Please input a 2nd arg\n");
        return 1;
    }

    // check if symbols present
    for (int i = 0; i < strlen(letters); i++)
    {
        if (!(isalpha(letters[i])))
        {
            printf("Please exclude symbols\n");
            return 2;
        }
    }
    // string letters = get_string("Letters: \n");
    // loop through the string
    for (int i = 0; i < strlen(letters) - 1; i++)
    {
        // letters later in the alphabet have >value
        if (letters[i + 1] < letters[i])
        {
            printf("No, alphabetical order pls\n");
            return 0;
        }
    }
    // if no letters > value than before
    printf("Yes\n");
    return 0;
}
