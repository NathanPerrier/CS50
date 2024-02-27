#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int integers[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (integers[j] > integers[j + 1])
                swap(&integers[j], &integers[j + 1]);
}

/* Function to print an array */
void printArray(int integers[], int max)
{
    int i;
    for (i = max; i >= 16; i--)
        printf("%d\n", integers[i]);

}

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: Invalid\n");
        return 1;
    }
    int max = 0;
    int array[50000];
    FILE *file = fopen(argv[1], "r");
    int i = 0;
    int integers[max];
    if (file != NULL) {
        while(!feof(file))
        {
            fscanf(file, "%d", &array[max]);
            max++;
        }
        printf("max: %i\n", max);
        while (!feof(file) && i < max) {
            if (fscanf(file, "%d", &integers[i++]) != -1) {
                integers[i] = integers[i-1];
                //printf("%d\n", integers[i]);
            }
        }
        fclose(file);
    }
    else
    {
        printf("Unable to open file\n");
        return 0;
    }


    int n = sizeof(integers) / sizeof(integers[0]);
    bubbleSort(integers, n);
    printf("Sorted array: \n");
    printArray(integers, max);
    return 0;

}