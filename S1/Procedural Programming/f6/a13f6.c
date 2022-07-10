#include <stdio.h>
#include <math.h>
#include "simpio.h"
#include "genlib.h"

void decompose(long num, int *digitCount, double *digitAverage, int *maxDigit);

int main() {

    int digitCount,maxDigit;
    double digitAverage;
    long number;

    number = (printf("Please insert non-negative number:"), GetLong());
    if (number == 0)
    {
        digitCount = maxDigit = digitAverage = 0;
    }
    else if (number > 0)
    {
        decompose(number,&digitCount,&digitAverage,&maxDigit);
    }
    else {return 0;}

    printf("Digits: %d\n",digitCount);
    printf("Average: %.3f\n",digitAverage);
    printf("Max: %d\n",maxDigit);

    return 0;
}

void decompose(long num, int *digitCount, double *digitAverage, int *maxDigit)
{
    int digitSum=0;
    long tempNum = num;

    *digitCount = floor(log10(num)+1);

    while (tempNum > 0)
    {
        digitSum += tempNum%10;
        tempNum /= 10;
    }

    *digitAverage = (double)digitSum/(*digitCount);

    tempNum = num;
    *maxDigit = 0;
    while (tempNum > 0)
    {
        if (tempNum%10 > *maxDigit)
        {
            *maxDigit = tempNum%10;
        }
        tempNum /= 10;
    }
}
