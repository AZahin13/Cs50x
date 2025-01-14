// I accidentally overcomplicated a simple program -.-

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
// this is preprocessing macro
// replaces MAX with 9
#define MAX 9

// Candidates have name and vote count
// making a new data type for candidates
typedef struct
{
    string name;
    int votes;
} candidate;

// Function prototypes
bool vote(string name);

// candidates is an array of (candidate data type)s
candidate candidates[MAX];

// global variables
int candidate_count;
int voter_count;

int main(int argc, char *argv[]) // accept command line arg
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // number of candidates
    candidate_count = argc - 1; // minus the program arg

    // check for MAX
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    // check for MIN
    else if (candidate_count == 1)
    {
        printf("%s\n", argv[1]);
        return 0;
    }
    // Populate array of candidates
    else
    {
        for (int i = 0; i < candidate_count; i++) // i is the determinant
        {
            candidates[i].name = argv[i + 1]; // assigning argv to the na,e
            candidates[i].votes = 0; // initialising all votes = 0
        }
    }

    // get user input on number of voters
    voter_count = get_int("Number of voters: ");

    // calc min votes
    int min_votes = (voter_count/2) + 1;

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        while(true) // to loop if invalid
        {
            string name = get_string("Voter %i, Name of candidate of choice: ", i+1); // get the name

            // check the name
            if (!vote(name))
            {
                printf("Invalid vote. Name does not exist\n"); // restart the voting
            }
            else // candidate found
            {
                for (int j = 0; j < candidate_count; j++) // check which candidate was found
                {
                    if (strcmp(name, candidates[j].name) == 0) // assign vote to matching candidate
                    {
                        candidates[j].votes ++;

                        if (candidates[j].votes == min_votes) // check if min vote reached, winner
                        {
                            printf("%s\n", candidates[j].name);
                            return 0;
                        }
                    break; // one found break out of the candidates list
                    }
                }
            break; // if not reached, get out of the loop to next voter
            }
        }
    }
    printf("votes are equal\n"); // if for loop completed and no winner found
    return 0;
}

// check if name is there
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
       if (strcmp(name, candidates[i].name) == 0)
       {
        return true;
       }
    }
    return false;
}

