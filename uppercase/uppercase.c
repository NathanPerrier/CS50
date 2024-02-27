#include <cs50.h> //includes nessasry libaries
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i])) //if it is lowercase
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", tolower(s[i]));
        }
    }
    printf("\n");


}