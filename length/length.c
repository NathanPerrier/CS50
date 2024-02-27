#include <cs50.h> //includes nessasry libaries
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Word: ");
    int length = string_length(name);
    printf("length: %i\n", length);
}

int string_length(string s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return i;
}