c

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
string lower(string word);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX) //if amount of arguments is larger than the max number of candidates alowed
    {
        printf("Maximum number of candidates is %i\n", MAX); //print the max number of candidates allowed
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
            //voter_count++;
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //name = lower(name);  set the name entered to lowercase (for accessability perposes)
    int x = 0; //set x to 0
    for (int i = 0; i < candidate_count; i++)  //for every candidate
    {
        int comparison = strcmp(name, candidates[i].name); //uses strcmp to compare the two string entered and the list of candidates
        if (comparison == 0) //if the strings are identical (0) then add 1 to the amount of votes
        {
            candidates[i].votes++; //adds to the ote of the candidate
        }
        else
        {
            x++;
        }
    }
    if (x == candidate_count) //if the string entered does not match any of the candidates return 'false'
    {
        return false;
    }
    return true;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int highest_candidate_vote = 0;  //set's the highest score to 0
    for (int i = 0; i < candidate_count; i++) //get the highest voted candidates
    {

        if (candidates[i].votes > highest_candidate_vote) //if they are higher than the highest amount of votes
        {
            highest_candidate_vote = candidates[i].votes; //set the highest amount to that candidates votes
        }

    }
    for (int i = 0; i < candidate_count; i++) //print the highest voted candidates
    {

        if (candidates[i].votes == highest_candidate_vote) //if the candidate matches the highest amount of votes, print their name
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

string lower(string word)  //set's the word entered to lowercase
{
    for (int x = 0; x < strlen(word); x++) //for the length of the word
    {
        word[x] = tolower(word[x]); //set each character to lowercase
        return word; //return the word
    }
    return word;
}