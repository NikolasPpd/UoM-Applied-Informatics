#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long purchaseAmount;
    double profit, saleAmount;
    int rate;

    printf("Dose tin kathari aksia: ");
    purchaseAmount = GetLong();
    printf("Dose to pososto kerdous: ");
    rate = GetInteger();

    profit = purchaseAmount*(rate/100.0);
    printf("To kerdos einai %g", profit);
    saleAmount = purchaseAmount + profit;
    printf("\nTo sinoliko poso einai %g", saleAmount);
    return 0;

}
