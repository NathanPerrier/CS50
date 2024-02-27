#include <cs50.h> //includes nessasry libaries
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int i = 0;
    string word;
    char c[i];
    do {
        word = get_string("word: ");

        for (i = 0, n = strlen(word); i < n; i++)
        {
            printf("%c", word[i]);
        }
    }
    while (isalpha(c[i]) == false);



}