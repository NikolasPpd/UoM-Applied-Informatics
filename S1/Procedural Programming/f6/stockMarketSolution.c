/* Stock Market Analysis */

#include <stdio.h>

float findMaxTab(int size, float arr[]);
int fillIntTab(float max, int size, float interestingArr[], float boringArr[]);
void printLine(int length);
void printArr(int size, float arr[]);
void printArrWithMax(int size, float arr[], float max);
float cdsAssessment(float cds, int risk);
void high_low(int row, int col, int which, float matrix[row][col], int *high, int *low);

int main(){
    float stock_prices[10] = {34.5, 22.4, 77.8, 22.1, 10.0, 11.25, 12, 13, 16, 20.5 };
    float deriv_prices[5] = {30.5, 21.4, 89.8, 20.1, 10.0};
    float cds_prices[11] = {38.5, 33.4, 67.8, 12.1, 16.0, 10.25, 11, 23, 36, 10.1 ,30.4};
    int risk[11] = {90,10,20,30,50,60,30,30,30,10,10};

    float deriv_day_data[5][10] =   {{30.5,25,22,32.3,30.5,32.6,38.9,40,22,30.5},
                                    {22.5,21.4,14,40.3,22.5,12.6,38.9,40,39,21.4},
                                    {30.5,25,22,89.8,34.5,89.8,38.9,40,30,89.8},
                                    {20.2,35,20.1,12.3,20.1,32.6,38.9,40,22,20.1},
                                    {45.5,10.0,22,10.0,14.5,23.6,48.9,8,10.0,10.0}};

    float interesting_stock[10];
    int ni_stock, ni_cds;
    float interesting_cds[11];
    int i;
    float max_stock, max_deriv, max_cds;
    int low, high;

    /* Calculating Max Values */
    max_stock = findMaxTab(10,stock_prices);
    max_deriv = findMaxTab(5,deriv_prices);
    max_cds = findMaxTab(11,cds_prices);

    /* Finding Interesting Values */
    ni_stock = fillIntTab(max_stock,10,interesting_stock,stock_prices);
    ni_cds = fillIntTab(max_cds,11,interesting_cds,cds_prices);

    /* Printing */

    printf("Stock Prices.\n");
    printLine(30);
    printArrWithMax(10, stock_prices, max_stock);
    printf("Interesting Stock Prices:");
    printArr(ni_stock, interesting_stock);
    printLine(10);

    /* Derivatives */
    printf("Derivative Prices.\n");
    printLine(30);
    printArrWithMax(5, deriv_prices, max_deriv);
    printLine(10);

    /* Cds Prices */
    printf("CDS Prices.\n");
    printLine(30);
    printArrWithMax(11, cds_prices, max_cds);
    printf("Interesting CDS Prices:");
    printArr(ni_cds, interesting_cds);
    printLine(30);

    printf("CDS Assessment\n");
    for (i=0;i<11;i++)
    {
        printf("CDS assessment: cds %4.2f Risk %d Value %4.2f\n",cds_prices[i],risk[i],cdsAssessment(cds_prices[i],risk[i]));
    }

    printLine(30);
    printf("Derivative Low High\n");
    for (i=0;i<5;i++)
    {
        high_low(5,10,i,deriv_day_data,&high,&low);
        printf("Devirative %d, high %d / low %d values.\n",i,high,low);
    }
    printLine(30);

    return 0;
}

float findMaxTab(int size, float arr[])
{
    float max;
    int i;
    max = arr[0];
    for(i=1;i<size;i++)
    {
        if (arr[i] > max) {max = arr[i];}
    }
    return max;
}

int fillIntTab(float max, int size, float interestingArr[], float boringArr[])
{
    int ni=0,i;
    for(i=0;i<size;i++)
    {
        if (boringArr[i] > max / 2)
        {
            interestingArr[ni++] = boringArr[i];
        }

    }
    return ni;
}

void printLine(int length)
{
    int i;
    for(i=0;i<length;i++) printf("-");
    printf("\n");
}

void printArr(int size, float arr[])
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("[%4.2f] ",arr[i]);
    }
    printf("\n");
}

void printArrWithMax(int size, float arr[], float max)
{
    int i;
    printf("Max Price:: %4.2f \n",max);
    for(i=0;i<size;i++)
    {
        printf("%s(%3.2f) ",(max == arr[i] ? "-Max-" : ""),arr[i]);
    }
    printf("\n");
}

float cdsAssessment(float cds, int risk)
{
    if (cds<20.0 && risk<50) return 20;
    if (cds>=20.0 && risk<80) return (10 + (cds*risk)/100);
    return (100 + (cds*risk)/100);
}

void high_low(int row, int col, int which, float matrix[row][col], int *high, int *low)
{
    int j;
    (*high) = 0;
    (*low) = 0;

    for (j=0;j<col-1;j++)
    {
        if (matrix[which][j]>matrix[which][col-1]) (*high)++;
        if (matrix[which][j]<matrix[which][col-1]) (*low)++;
    }
}
