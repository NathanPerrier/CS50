#include <cs50.h>
#include <stdio.h>

void woof(void); //allows for functions to be declaired bellow another function that calls apon it

void example3(int n)
{
    for (int i = 0; i < n; i++)   //example 3
    {
        woof();
    }
}

int main(void)
{
    int x = 5;
    while (x > 0)                 //example 1
    {
        printf("meow!\n");
        x--;
    }

    for (int i = 0; i < 5; i++)   //example 2
    {
        woof();
    }

    example3(2);  //calls upon example 3 and set's n to 2
}


void woof(void)
{
    printf("woof!\n");
}