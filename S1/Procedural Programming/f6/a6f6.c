#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define N 5
#define INFO 4

void readData(int rows, int cols, int data[rows][cols]);
void FindMean(int rows, int cols, int data[rows][cols], int selection, double *male, double *female);

int main()
{
    int data[N][INFO];
    double maleAvg=0, femaleAvg=0;

    readData(N,INFO,data);

    FindMean(N,INFO,data,1,&maleAvg,&femaleAvg);
    printf("Mesos oros barous andrwn: %.1f\n",maleAvg);
    printf("Mesos oros barous gynaikwn: %.1f\n\n",femaleAvg);
    FindMean(N,INFO,data,2,&maleAvg,&femaleAvg);
    printf("Mesos oros ypsous andrwn: %.1f\n",maleAvg);
    printf("Mesos oros ypsous gynaikwn: %.1f\n\n",femaleAvg);
    FindMean(N,INFO,data,3,&maleAvg,&femaleAvg);
    printf("Mesos oros hlikias andrwn: %.1f\n",maleAvg);
    printf("Mesos oros hlikias gynaikwn: %.1f\n\n",femaleAvg);

    return 0;
}

void readData(int rows, int cols, int data[rows][cols])
{
    int i,index;

    for (i=0;i<rows;i++) //rows
    {
        index=0;
        printf("Dwse fylo: ");
        data[i][index++] = GetInteger();
        printf("Dwse baros: ");
        data[i][index++] = GetInteger();
        printf("Dwse ypsos: ");
        data[i][index++] = GetInteger();
        printf("Dwse ilikia: ");
        data[i][index] = GetInteger();
        printf("-----\n");
    }
}

void FindMean(int rows, int cols, int data[rows][cols], int selection, double *male, double *female)
{
    int i,maleCount=0,femaleCount=0;
    double maleSum=0, femaleSum=0;

    for (i=0;i<rows;i++) //rows
    {
        if (data[i][0] == 0)
        {
            maleSum += data[i][selection];
            maleCount++;
        }
        else if (data[i][0] == 1)
        {
            femaleSum += data[i][selection];
            femaleCount++;
        }
    }

    if (maleCount != 0)
    {
        *male = maleSum / maleCount;
    }
    if (femaleCount != 0)
    {
        *female = femaleSum / femaleCount;
    }
}
