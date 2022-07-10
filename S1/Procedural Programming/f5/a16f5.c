#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define SIZE 50

void populate(int row, int a[row]);
void printArr(int row, int a[row]);
int checkTable(int N, int row, int a[row], int NIndexes[row]);

int main() {

    int a[SIZE],NIndexes[SIZE];
    int N,occurrence;

    populate(SIZE,a);
    printArr(SIZE,a);
    printf("\n--------------");
    N = (printf("\nDose arithmo apo to 0 ews to 9: "),GetInteger());

    occurrence = checkTable(N,SIZE,a,NIndexes);
    printf("\no Arithmos 1 emfanizetai %d fores.\nStis Theseis:\n",occurrence);
    printArr(occurrence,NIndexes);
    printf("\n--------------");

    return 0;
}

void populate(int row, int a[row])
{
    int i;

    for (i=0;i<row;i++)
    {
        a[i] = rand() % 10;
    }
}

void printArr(int row, int a[row])
{
    int i;
    for (i=0;i<row;i++)
    {
        printf(" %d ",a[i]);
    }
}

int checkTable(int N, int row, int a[row], int NIndexes[row])
{
    int i,count=0,j=0;
    for (i=0;i<row;i++)
    {
        if (a[i] == N)
        {
            count++;
            NIndexes[j] = i;
            j++;
        }
    }
    return count;
}
