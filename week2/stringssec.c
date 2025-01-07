//check if a lowercase string is in alphabetical order
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    //get string from user
    string letters = get_string("Please enter letters in alphabetical order: ");
    int length = strlen(letters);
    //printf("%i \n", length);

    //check if char value is bigger than the other
    bool alphabetical = true;
    for (int i = 0; i < length - 1; i++)
    {
        if (letters[i]< letters[i + 1])
        {
            alphabetical = true;
        }
        else
        {
            printf("Noa\n");
            return 1;
        }
    }
    if (alphabetical == true)
    {
        printf("Yes\n");
    }
    return 0;
}
