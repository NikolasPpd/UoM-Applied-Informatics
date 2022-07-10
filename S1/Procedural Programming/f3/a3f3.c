#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long cratesIn, cratesOut, cratesInCost, cratesOutCost, cratesInTotalCost, cratesOutTotalCost;

    cratesInCost = cratesOutCost = cratesInTotalCost = cratesOutTotalCost = 0;

    while (TRUE){
        cratesIn = (printf("Arithmos kibwtiwn eswterikou? "), GetLong());
        if (cratesIn == -9999) break;
        cratesOut = (printf("Arithmos kibwtiwn exwterikou? "), GetLong());
        cratesInCost = cratesIn*3500;
        cratesOutCost = cratesOut*5000;
        printf("%10ld%10ld%10ld\n",cratesInCost,cratesOutCost,cratesInCost+cratesOutCost);
        cratesInTotalCost += cratesInCost;
        cratesOutTotalCost += cratesOutCost;
    }

    printf("%10ld%10ld%10ld\n",cratesInTotalCost,cratesOutTotalCost,cratesInTotalCost+cratesOutTotalCost);

    return 0;
}
