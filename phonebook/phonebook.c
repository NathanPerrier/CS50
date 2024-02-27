#include <cs50.h> //includes nessasry libaries
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];
    
    people[0].name = "Carter";
    people[0].number = "0401737213";

    people[1].name = "Nathan";
    people[1].number = "0427370979";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "Nathan") == 0)
        {
            printf("Found!, Number: %s\n", people[i].number);
            return 0;
        }
    }
     printf("Not Found\n");
     return 1;
}