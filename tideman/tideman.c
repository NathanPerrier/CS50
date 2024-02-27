#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote (int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++) //for every candidate
    {
        if(strcmp(name, candidates[i]) == 0) //if the name is the same as the current candidate in the loop (check if name is valid)
        {
            // Update ranks array with rank preference by...
            ranks[rank] = i; //set the candidates rank as the variable i
            return true; //return true
        }
    }
    return false; //if name does not match any of the candidates then retun false
}

// Update preferences given one of the voter's ranks
void record_preferences(int ranks[])
{

    for (int i = 0; i < candidate_count; i++) //for every candidate
    {
        for (int j = i + 1; j < candidate_count; j++) //for every second candidate????
        {
            preferences[ranks[i]][ranks[j]] += 1; // Update number of voters who prefer [i] to [j]
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++) //for every candidate
    {
        for (int j = i + 1; j < candidate_count; j++) //for every second candidate
        {
            if (preferences[i][j] > preferences[j][i]) //if preference one is greater than preference two
            {
                pairs[pair_count].winner = i; //set winner to i as they were greater than prefernce two
                pairs[pair_count].loser = j; //set j to the loser
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i]) //if preference two is greater than preference one
            {
                pairs[pair_count].winner = j; //set winner to j as they were greater than prefernce two
                pairs[pair_count].loser = i; //set i to loser
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = pair_count - 1; i >= 0 ; i--) //for every pair
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if ((preferences[pairs[j].winner][pairs[j].loser]) < (preferences[pairs[j + 1].winner][pairs[j + 1].loser])) //If the pair at position j + 1 has a greater strength of victory than the pair at position j, then they are swapped using a temporary variable
            {
                pair temp = pairs[j]; //set pair j to the variable temp
                pairs[j] = pairs[j + 1]; // pair j + 1
                pairs[j + 1] = temp; // set pair j + 1 to the temp variable
            }
        }
    }
    return;
}

bool is_circle(int loser, int winner)
{
    // Base Case 1: if path exist
    if (loser == winner) {
        return true; // it forms a cycle
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if(locked[loser][i]) //check if loser is locked with a candidate
        {
            return is_circle(i, winner); // check if that candidate is locked with  winner
        }
    }

    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++) //for every pair
    {
        if (!is_circle(pairs[i].loser, pairs[i].winner)) // If cycle function returns false, lock the pair
        {
            locked[pairs[i].winner][pairs[i].loser] = true; //lock the pair
        }

    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // Winner is the candidate with no arrows pointing to them
    for (int i = 0; i < candidate_count; i++) //for every candidate
    {
        int false_count = 0; //set false_count as 0 to integer to count the number of false values
        for (int j = 0; j < candidate_count; j++) //for every candidate
        {
            if (locked[j][i] == false) //iterating false_count if a false value is found locked
            {
                false_count++;
                if (false_count == candidate_count) //if If false_count is equal to candidate_count then the entire column is false and that candidate can be declared as a source of the graph and their name printed
                {
                    printf("%s\n", candidates[i]); //print candidate
                }
            }
        }
    }
    return;
}