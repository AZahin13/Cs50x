//Let's learn how to use variables
//I want to make a programme that counts to 10
#include <stdio.h>
#include <cs50.h>
#include <unistd.h>

int main(){
    string character = get_string("What is your name?\n");
    char play = get_char("Hello %s, would you like to play a game? (y/n)\n", character);

    if (play == 'y' || play == 'Y')
    {
        printf("We're going to play hide and seek ;)\n");
        sleep(2);
        printf("Go now, I will count to 10\n");
        sleep(2);

        int count = 0;

        for (int i=0; i<10; i++)
        {
            printf("%i\n", count);
            sleep(1);
            count++;
        }
            printf("Ready or not, here I come!\n");
    }
    else if (play == 'n' || play == 'N')
    {
        printf("Aww, come back when you find a slice of confidence\n");
    }

    return 0;
}
