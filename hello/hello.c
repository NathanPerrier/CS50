#include <cs50.h> //includes nessasry libaries
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");  //gets the users name using get_string()
    printf("hello, %s\n", answer);  //prints hello, then the users name using the name gathered in the variable answer
}