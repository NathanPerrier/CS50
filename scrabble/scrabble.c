#include <cs50.h> //includes nessasry libaries
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int POINTS [] = {1, 3,  3,  2,  1,  4,  2,  4,  1,  8,  5,  1,  3,  1,  1,  3,  10, 1,  1,  1,  1,  4,  4,  8,  4,  10}; //stores all points

int compute_score(string word); //declares function

int main(void)
{
    string player1 = get_string("Player 1: "); //gets player1's word
    string player2 = get_string("Player 2: "); //gets player2's word

    int score1 = compute_score(player1); //gets player1's score
    int score2 = compute_score(player2); //gets player2's score

    if (score1 > score2)   //if player 1 has a larger score then player 1 wins
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1) // if player 3 has a larger score then payer 2 wins
    {
        printf("Player 2 wins!\n");
    }
    else  //else their scores are equal and it's a tie
    {
        printf("Tie!\n");
    }

}
int compute_score(string word)
{
     int points = 0; //set points to 0
     for (int i = 0; i < strlen(word); i++)  //for every element
    {
        if (isalpha(word[i]))  //if the letter is in the alphabet
        {
            char letter = tolower(word[i]); //set letter to lowercase
            points += POINTS[letter - 'a']; //calculate the point allocated to the letter
        }
    }
    return points; //return points
}