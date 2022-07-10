#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define ROWS 10
#define COLS 10

void populate_data(int usedRows, int usedCols, int maxRows, int maxCols, int matrix[maxRows][maxCols]);
void print_array(int usedRows, int usedCols, int maxRows, int maxCols, int matrix[maxRows][maxCols]);
void change_array(int usedRows, int usedCols, int maxRows, int maxCols, int matrix[maxRows][maxCols]);

int main() {

    int R, C;
    int matrix[ROWS][COLS];

    R = (printf("Dwse ton arithmo twn grammwn: "),GetInteger());
    C = (printf("Dwse ton arithmo twn sthlwn: "),GetInteger());
    populate_data(R,C,ROWS,COLS,matrix);

    printf("ARXIKOS PINAKAS\n");
    print_array(R,C,ROWS,COLS,matrix);

    change_array(R,C,ROWS,COLS,matrix);
    printf("ALLAGMENOS PINAKAS\n");
    print_array(R,C,ROWS,COLS,matrix);

    return 0;
}

void populate_data(int usedRows, int usedCols, int maxRows, int maxCols, int matrix[maxRows][maxCols])
{
    int i,j;

    for (i=0;i<usedRows;i++)
    {
        for (j=0;j<usedCols;j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}

void print_array(int usedRows, int usedCols, int maxRows, int maxCols, int matrix[maxRows][maxCols])
{
    int i,j;

    for (i=0;i<usedRows;i++)
    {
        for (j=0;j<usedCols;j++)
        {
            printf("%2d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void change_array(int usedRows, int usedCols, int maxRows, int maxCols, int matrix[maxRows][maxCols])
{
    int i,j,lineMax=-1,maxPos;

    for (i=0;i<usedRows;i++)
    {
        lineMax=-1;
        for (j=0;j<usedCols;j++)
        {
            if (matrix[i][j] > lineMax)
            {
                lineMax = matrix[i][j];
                maxPos = j;
            }
        }
        for (j=0;j<maxPos;j++)
        {
            matrix[i][j] = lineMax;
        }
    }
}
