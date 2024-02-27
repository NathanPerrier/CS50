#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long cardNumber;
    long cardNumber4;
    int length;
    do      //get's the card number
    {
        length = 0;
        cardNumber = get_long("Card Number: ");
        cardNumber4 = cardNumber;
        if (length < 13 || length > 16) // if the length is not valid then exit
        {
            //printf("INVALID\n");
            void exit(int status);
        }
        while (cardNumber) //for every digit
        {
            cardNumber /= 10; //devide by 10
            length++; //add 1 to length
        }
    }
    while (length < 13 || length > 16);  //while card length is not valid repeat do
    long cardNumber2 = cardNumber4, cardNumber5 = cardNumber4; //dclare vaiables
    int digits[length];
    int sum_even;
    int amount2 = 0;
    int amount = 1;
    int sum_odd_digits;
    int sum_odd_digit, sum_odd_digit2, sum_odd_digit3;
    int odd_digits[length];
    int i;
    for (int n = 0; n < length; n++)  //for every digit
    {
        digits[n] = cardNumber2 % 10; //put each digit in the variable
        cardNumber2 /= 10;  // divide by 10
        amount = amount + 1; // amount + 1
        amount2 = amount2 + 1;
        if (amount == 2) //if amount is equal to 2 add digit to even sum and set amount to 0
        {
            sum_even = sum_even + digits[n];
            amount = 0;
        }
        if (amount2 == 2) //if amount is equal to 2 add digit to even sum and set amount to 0
        {
            odd_digits[n] = digits[n];
            sum_odd_digit = odd_digits[n]*2, sum_odd_digit2 = sum_odd_digit, sum_odd_digit3 = sum_odd_digit;
            for (int x = 0; x < sum_odd_digit2; ++x)
            {
                sum_odd_digit2 /= 10;
            }
            if (sum_odd_digit2 == 1)
            {
                sum_odd_digit3 %= 10;
                sum_odd_digits = sum_odd_digits + sum_odd_digit3 + sum_odd_digit2;
                amount2 = 0;
            }
            else
            {
                sum_odd_digits = sum_odd_digits + sum_odd_digit;
                amount2 = 0;
            }
        }

    }
    int sum = sum_odd_digits + sum_even;
    if (sum % 10 != 0) //if the last digit of sum is not 0 then print INVALID
    {
        printf("INVALID\n");
        return 0;
    }
    if ((length != 13) && (length != 15) && (length != 16))
    {
        printf("INVALID\n");
    }
    if ((digits[15] == 5) && (0 < digits[14] && digits[14] < 6)) //if cardNumber represents a MC then print MASTERCARD
    {
        printf("MASTERCARD\n");
    }
    else if ((digits[14] == 3) && (digits[13] == 4 || digits[13] == 7)) //if cardNumber represents a Amex then print AMEX
    {
        printf("AMEX\n");
    }
    else if (digits[12] == 4 || digits[13] == 4 || digits[14] == 4 || digits[15] == 4) //if cardNumber represents a visa then print VISA
    {
        printf("VISA\n");
    }
    else //else if the card number does not match the rest then it is invalid
    {
        printf("INVALID\n");
    }
}


