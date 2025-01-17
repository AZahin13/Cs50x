// a progam using the vote-ranking system
// modified by the runoff method

// N.B. Lesson learnt here was that candidates is an array for type candidate
// so using dot operators need to be to candidates[i] not candidate
// as candidate is a single structure. candidate.name would be viable
// in the case of only a single candidate type structure being used

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    // connect candidate names to struct
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // get number of voters up to 100
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Depenidng on number of voters: Keep querying for votes
    for (int i = 0; i < voter_count; i++) // iterate over voters
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++) // iterate over ranking
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name)) // vote function checks if it's a valid candidate
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min(); // min returns 0 if it's not a tie
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++) // iterate over every candidate
    {
        if (strcmp(candidates[i].name, name) == 0) // compare names
        {
            preferences[voter][rank] = i; // succesfully stores which candidate returns true
            return true;
        }
    }
    return false; // if candidate is not found through all; return false
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++) // go over voters
    {
        int rank = 0;                  // rank keeps track of voters preferences, goes next if elim
        while (rank < candidate_count) // iterates over voters candidate rank, prevents OOB access
        {
            // check if elimnated
            // if candiate at voter[i] 0 rank is eliminated, move to next rank
            // preferences is the index of a candidate[i] where i = preference[voter][ranking]
            if (candidates[preferences[i][rank]].eliminated)
            {
                rank++; // updates preference
            }
            else
            {
                candidates[preferences[i][rank]].votes++; // add a vote
                break; // break loop once vote hate been added, move to next voter
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // check min number of votes needed
    int min_winningvotes = (voter_count / 2) + 1;

    // if candidate wins, return true
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min_winningvotes)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    // else (tie), return false
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // finding the least votes
    int minNum_votes = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        // remove eliminated candidates
        if (candidates[i].eliminated)
        {
            continue;
        }

        // compare for least votes
        if (candidates[i].votes < minNum_votes)
        {
            minNum_votes = candidates[i].votes;
        }
    }
    return minNum_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // check for tie
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated) // remove eliminated candidates
        {
            continue;
        }

        if (candidates[i].votes != min)
        {
            return false; // not all candidates have the same min
        }
    }

    // return true if all candidates = min
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min) // candidates with the least votes
        {
            candidates[i].eliminated = true; // eliminate them
        }
    }
}
