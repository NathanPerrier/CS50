#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) //if the commandline argument is <2 or >2 (has to equal 2)
    {
        printf("Enter only one command-line argument\n");
        return 1; //end function
    }
    if (strlen(argv[1]) != 26) //if the length of the argument does not equal 26 (length of alphabet) then end function
    {
        printf(" Must contain 26 characters.\n");
        return 1; //end function
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)  //for every element
    {
        if (isalpha(argv[1][i]) == false) //if every element in argv is not in the alphabet then end function
        {
            printf(" Must only contain alphabetic characters.\n");
            return 1;  //end function
        }
        for (int x = i + 1; x < n; x++)  //for every element
        {
            if (argv[1][i] == argv[1][x])  //if the argument has a repeated character then end function
            {
                printf(" Must not contain repeated alphabeth\n");
                return 1; //end function
            }
        }
    }
    string text = get_string("text: "); //get the text that is to tbe incrypted
    printf("ciphertext: ");
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)  //for every element
    {
        char char_lower = argv[1][text[i] - 97];    //calculation to print the encipher text
        char char_upper = argv[1][text[i] - 65];    //calculation to print the encipher text
        if (isupper(text[i]))                       //if the text character entered is uppercase then print the encryption character in uppercase
        {
            printf("%c", toupper(char_upper));      //print character as uppercase
        }
        else if (islower(text[i]))                  //if the text character entered is lowercase then print the encryption character in lowercase
        {
            printf("%c", tolower(char_lower));      //print the character as lowercase
        }
        else                                        //else print it without changing because it is the same
        {
            printf("%c", text[i]);
        }

    }
    printf("\n");       //print newline
}