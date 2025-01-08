// This is a program to determine a text's reading level
// The text is assign a grade that corresponds to it's reading level
// calculations are made based on the Coleman - Liau index

// PSEUDOCODE:
// a program to determine the reading level
// outputs, before grade 1, Grade 1-16, Grade 16+
// readibility test using Coleman-Liau index
// CL index = 0.0588 x L - 0.296 x S - 15.8
// L average number of letters per 100 words
// S average number of sentences per 100 words
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // obtain text
    string text = get_string("Text: ");
    int textlen = strlen(text);

    // count number of letters, words, sentences
    // count letters
    float letters = 0;
    for (int i = 0; i < textlen; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    // printf("# of letters: %f\n", letters);

    // words - count the spaces?
    float words = 1;
    for (int i = 0; i < textlen; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    // printf("# of words: %f\n", words);

    // sentences # of fullstops
    float sent = 0;
    for (int i = 0; i < textlen; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sent++;
        }
    }
    // printf("# of sentences: %f\n", sent);

    // calculate CL index
    float CL;
    float L = (letters / words) * 100;
    float S = (sent / words) * 100;

    // all variables that int w floats
    // must be floats else will truncate
    // truncate = fractions < 1 = 0
    CL = (0.0588 * L) - (0.296 * S) - 15.8;

    // Print out grade level
    // printf("Grade %.2f\n", CL);

    // asign a grade
    int grade = round(CL);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (grade > 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
        return 0;
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// my mistakes here was not using floats: truncation
// and also not defining parameters properly
