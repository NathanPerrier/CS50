#include <cs50.h>
#include <stdio.h>

float discount(float price, int percentage);

int main(void)
{
    float regular = get_float("Regular price: ");
    int sale = get_int("Sale: ");
    float fprice = discount(regular, sale);
    printf("Final price: %.2f\n", fprice);
}

float discount(float price, int percentage)
{
    return price * (100 - percentage) / 100;
}