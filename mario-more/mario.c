#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int height;           //declares height
  do
  {
    height = get_int("Height: ");           //asks for height
  }
  while (height < 1 || height > 8);         //while height is less then 1 or more than 8 it will keep asking for height

  int i;                                    //declares i
  for (i = 1; i <= height; i++) {   //while height is greater than or equal to i --
      int column;                           //declares column
      for (column = height; column > i; column--)       //makes a invisable triangle using an inverse triangle
      {
          printf(" ");          //prints a space instead of #
      }
      for (column = 0; column < i; column++)   //while column is smaller than i
      {
           putchar('#');            //print char #
      }
      printf("  ");                 // create a space of 2 between the two triangles
      for (column = 0; column < i; column++)        //while column is smaller than i
      {
          putchar('#');                             // print char #
      }
     putchar('\n');                     //print new line
  }
}