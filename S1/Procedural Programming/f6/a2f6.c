#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define SIZE 100

int readNumbers(int size, int table[size]);
void findMinMax(int usedSize, int size, int table[size], int *min, int *max);

int main() {

    int numbers[SIZE];
    int usedSize;
    int min, max;

    usedSize = readNumbers(SIZE, numbers);
    findMinMax(usedSize,SIZE,numbers,&min,&max);

    printf("The range of values is %d-%d",min,max);

    return 0;
}

int readNumbers(int size, int table[size])
{
    int count=0,num;

    printf("Enter the elements of the array, one per line.\n");
    printf("Use -1 to signal the end of the list.\n");

    while (count<size)
    {
        num = (printf("? "), GetInteger());
        if (num == -1) break;
        table[count] = num;
        count++;
    }
    return count;
}

void findMinMax(int usedSize, int size, int table[size], int *min, int *max)
{
    int i;

    *min = *max = table[0];

    for (i=1;i<usedSize;i++)
    {
        if (*min > table[i])
        {
            *min = table[i];
        }
        else if (*max < table[i])
        {
            *max = table[i];
        }
    }
}
