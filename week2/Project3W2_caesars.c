// A program to implement caesar's cipher

//PSEUDOCODE
// receive key from command line
// receive plaintext from user
// encrypt text using key
// display ciphertext
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ciph(char ptc, int ky);

int main(int argc, string argv[])
{
    // check if arg input available + handle too many arguments
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // make sure it's after the argc chat
    // else key will be assigned to argv[1]
    string initkey = argv[1];
    int iklen = strlen(initkey);

    // check if key is numerical
    //  use isdigit function from ctype
    for (int i = 0; i < iklen; i++)
    {
        if (!(isdigit(initkey[i])))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // change key to int
    // convert using atoi string to int
    // part of stdlib.h
    // %26 helps if the number is too large
    // if < 26 = remainder of %26 too so doesn't change it
    // a modulo here is not necessary but it improves efficiency
    // otherwise the key would loop a large number
    // which takes up memory and reduces efficiency
    int key = atoi(initkey) % 26;

    // receive plaintext
    string ptext = get_string("plaintext:  ");
    int ptlen = strlen(ptext);

    char ctext[ptlen + 1]; // an array of char = string, +1 for null term

    // cipher plain text, char by char
    for (int i = 0; i < ptlen; i++)
    {
        ctext[i] = ciph(ptext[i], key);
    }

    ctext[ptlen] = '\0'; // allocate the null term

    // display ciphertext
    printf("ciphertext:  %s", ctext);
    printf("\n");
    return 0;
}

char ciph(char ptc, int ky)
{
    char cipchar = 0;
    if (isalpha(ptc))
    {
        if (ptc >= 'A' && ptc <= 'Z')
        {
            cipchar = (ptc - 'A' + ky) % 26 + 'A';
        }
        else if (ptc >= 'a' && ptc <= 'z')
        {
            cipchar = (ptc - 'a' + ky) % 26 + 'a';
        }
    }
    else
    {
        cipchar = ptc;
    }
    return cipchar;
}
