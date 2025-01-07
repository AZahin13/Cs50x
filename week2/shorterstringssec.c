//this is embarassing
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string letters = get_string("Letters: \n");
    for (int i = 0; i < strlen(letters) - 1; i++)
    {
        if (letters[i+1] < letters[i])
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

