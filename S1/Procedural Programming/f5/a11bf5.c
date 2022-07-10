#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define CITIES 10
#define DAY_PARTS 3

void ReadData(int row, int col, double temperatures[row][col]);
double CalculateAverage(int row, int col, double temperatures[row][col]);
void CalculateAvCity(int row, int col, double temperatures[row][col], double average[]);
void CalculateMaxDeviation(int row,int col,double avg,double maxDeviation[row],double temperatures[row][col]);
void Print_Results(double avg, int row, double average[row], double maxDeviation[row]);
double absValue(double num);

int main()
{
    double temperatures[CITIES][DAY_PARTS];
    double average[CITIES];
    double maxDeviation[CITIES];
    double avg;

    ReadData(CITIES,DAY_PARTS,temperatures);
    avg = CalculateAverage(CITIES,DAY_PARTS,temperatures);
    CalculateAvCity(CITIES,DAY_PARTS,temperatures,average);
    CalculateMaxDeviation(CITIES,DAY_PARTS,avg,maxDeviation,temperatures);
    Print_Results(avg,CITIES,average,maxDeviation);

    return 0;
}

void ReadData(int row, int col, double temperatures[row][col])
{
    int i,j;

    for (i=0;i<row;i++)
    {
        for (j=0;j<col;j++)
        {
            printf("Temp of City %d During %d %d-hour period: ",i,j,24/DAY_PARTS);
            temperatures[i][j] = GetReal();
        }
    }
}

double CalculateAverage(int row, int col, double temperatures[row][col])
{
    int i,j;
    double natSum=0,natAverage;

    for (i=0;i<row;i++)
    {
        for (j=0;j<col;j++)
        {
            natSum += temperatures[i][j];
        }
    }
    natAverage = natSum/(row*col);
    return natAverage;
}

void CalculateAvCity(int row, int col, double temperatures[row][col], double average[])
{
    int i,j;
    for (i=0; i<row; i++)
    {
        average[i] = 0;
        for (j=0; j<col; j++)
        {
            average[i] += temperatures[i][j];
        }
        average[i] /= col;
    }
}

void CalculateMaxDeviation(int row,int col,double avg,double maxDeviation[row],double temperatures[row][col])
{
    int i,j;
    double deviance;
    for (i=0;i<row;i++)
    {
        deviance=0;
        for (j=0;j<col;j++)
        {
            if (absValue(avg-temperatures[i][j]) > deviance){
                deviance = absValue(avg-temperatures[i][j]);
            }
        }
        maxDeviation[i] = deviance;
    }
}

void Print_Results(double avg, int row, double average[row], double maxDeviation[row])
{
    int i;
    printf("%.1f\n",avg);
    for (i=0;i<CITIES;i++)
    {
        printf("City %d  %.1f  %.1f\n",i,average[i],maxDeviation[i]);
    }
}

double absValue(double num)
{
    if (num < 0) return (-num);
    return num;
}

