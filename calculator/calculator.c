#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("x: "); //first number
    long y = get_long("y: "); //seccond number
    long sum = x + y;
    printf("sum: %li\n", x + y);
    if (x < y)
    {
        printf("x is smaller than y\n");
    }
    else if (x > y)
    {
        printf("x is bigger than y\n");
    }
    else
    {
        printf("x and y are equal\n");
    }
}