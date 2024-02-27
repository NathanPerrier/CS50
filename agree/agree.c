#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree to the terms of use (y/n)? ");
    if (c == 'y' || c == 'Y') // || = or      if you want and   && = and
    {
        printf("Great!\n");
    }
    else if (c == 'n' || c == 'N') // have to use single quotes for signle characters 
    {
        printf("Oh no!\n");
    }
}