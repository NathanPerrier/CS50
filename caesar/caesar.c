#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) //if the commandline argument is <2 or >2 (has to equal 2)
    {
        printf("Enter only one command-line argument\n");
        return 1; //end function
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)  //for every element
    {
        if (isdigit(argv[1][i]) == false) //if every element in argv is not in the alphabet then end function
        {
            printf(" Must not contain alphabetic characters.\n");
            return 1;  //end function
        }
    }
    string plaintext = get_string("Plaintext: "); //get the plaintext that is to tbe incrypted
    int key = atoi(argv[1]);
    int text_length = strlen(plaintext);
    int remainder = 26;
    int ascii;
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(plaintext[i]) != 0)
        {
            if (isupper(plaintext[i]))
            {
                ascii = 65;
            }
            else
            {
                ascii = 97;
            }
            plaintext[i] = (plaintext[i] - ascii);
            plaintext[i] = (plaintext[i] + key) % remainder;
            plaintext[i] = (plaintext[i] + ascii);
        }
        else
        {
            plaintext[i] = plaintext[i];
        }
    }
    printf("Ciphertext: %s", plaintext);
    printf("\n");
}