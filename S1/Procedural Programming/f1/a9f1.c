#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long purchaseAmount;
    double rate, amount, discount;

    printf("Dose tin aksia tou emporevmatos: ");
    purchaseAmount = GetLong();
    printf("Dose to pososto ekptosis: ");
    rate = GetReal();

    discount = purchaseAmount*rate;
    amount = purchaseAmount - discount;

    printf("To poso pliromis einai: %g", amount);
    printf("\nI ekptosi einai: %g", discount);

    return 0;
}

