#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define SALESMEN 4
#define PRODUCTS 5

void calculateSales(int S, int P, int salesPerson[S], int price[P], int sales[S][P]);
void calculateProductSales(int S, int P, int productSale[P], int sales[S][P]);
void maxArray(int size, int arr[size], int *max, int *pos);
void printArray(int size, int arr[size]);

int main() {

    int price[PRODUCTS] = {250, 150, 320, 210, 920};
    int sales[SALESMEN][PRODUCTS]={{10,4,5,6,7},
                                   {7,0,12,1,3},
                                   {4,19,5,0,8},
                                   {3,2,1,5,6}};
    int salesPerson[SALESMEN];
    int productSale[PRODUCTS];

    int maxRevenue, maxPosition;
    int maxItems, maxSalesman;

    calculateSales(SALESMEN,PRODUCTS,salesPerson,price,sales);
    calculateProductSales(SALESMEN,PRODUCTS,productSale,sales);

    printf("SalesMan-Sales\n");
    printArray(SALESMEN,salesPerson);
    maxArray(SALESMEN, salesPerson, &maxRevenue, &maxPosition);
    printf("Best SalesMan was %d with %d sales\n",maxPosition,maxRevenue);

    printf("Product-Items\n");
    printArray(PRODUCTS,productSale);
    maxArray(PRODUCTS, productSale, &maxItems, &maxSalesman);
    printf("Best Product was %d with %d items",maxSalesman,maxItems);

    return 0;
}

void calculateSales(int S, int P, int salesPerson[S], int price[P], int sales[S][P])
{
    int i,j;

    for (i=0;i<S;i++)
    {
        salesPerson[i] = 0;
        for (j=0;j<P;j++)
        {
            salesPerson[i] += sales[i][j] * price[j];
        }
    }

}

void calculateProductSales(int S, int P, int productSale[P], int sales[S][P])
{
    int i,j;

    for (i=0;i<P;i++)
    {
        productSale[i] = 0;
        for (j=0;j<S;j++)
        {
            productSale[i] += sales[j][i];
        }
    }
}

void maxArray(int size, int arr[size], int *max, int *pos)
{
    int i;
    *max = arr[0];
    *pos = 0;

    for (i=1;i<size;i++)
    {
        if (*max < arr[i])
        {
            *max = arr[i];
            *pos = i;
        }
    }
}

void printArray(int size, int arr[size])
{
    int i;

    for (i=0;i<size;i++)
    {
        printf("   %d     %d\n",i,arr[i]);
    }
}
