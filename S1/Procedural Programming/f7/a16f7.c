#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    char userString[100];
    char numbers[100];
    int sum=0,i,j=0;

    //read string from the user
    printf("Insert a string: ");
    gets(userString);

    //save all digits and calculate their sum
    for (i=0; userString[i] != '\0'; i++)
    {
        if (isdigit(userString[i]))
        {
            numbers[j] = userString[i];
            sum += (userString[i] - 48);
            j++;
        }
    }
    numbers[j] = '\0';

    //print the result
    i = 0;
    if (numbers[i] != '\0')
    {
        for (i=0; numbers[i] != '\0'; i++)
        {
            if (i==0)
            {
                printf("%c ", numbers[i]);
            }
            else
            {
                printf("+ %c ", numbers[i]);
            }
        }
        printf("= %d\n",sum);
    }
    else
    {
        printf("No digits in input.\n");
    }

    return 0;
}
