#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: "); //get's the users string input
    int words = 1;
    int letters = 0;
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++) //for every element in the text
    {
        if (isspace(text[i]) != 0) //if the element is a space add to the amount of words
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') //if the element is a closing character then add to sentences
        {
            sentences++;
        }
        else if (isalpha(text[i]) != 0) //if the element is a alphabetical character then add to letters
        {
            letters++;
        }
    }
    for (int i = 0; i < strlen(text); i++)
    {
        if (sentences == 0 && words > 2)
        {
            sentences++;
        }
    }
    float L = 100 * (float) letters / (float) words; //formula for L
    float S = 100 * (float) sentences / (float) words; //formula for S

    float textgrade = 0.0588 *  L - 0.296 * S  - 15.8; //calculation to find the corresponding grade level

    if (textgrade < 16 && textgrade >= 0)
    {
        printf("Grade %i\n", (int) round(textgrade)); //print the corresponding grade
    }
    else if (textgrade >= 16)
    {
        printf("Grade 16+\n"); //if more than 16 print '16+'
    }
    else
    {
        printf("Before Grade 1\n"); //else the text if below grade 1 standards
    }

}