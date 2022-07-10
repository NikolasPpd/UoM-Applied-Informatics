#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int appliances, b50, b20, b5;

    printf("Dose to plithos ton siskevon: ");
    appliances = GetInteger();

    b50 = appliances / 50;
    appliances -= b50*50;
    b20 = appliances / 20;
    appliances -= b20*20;
    b5 = appliances / 5;
    appliances -= b5*5;

    printf("50:\t%d\n20:\t%d\n5:\t%d\n1:\t%d", b50, b20, b5, appliances);

    return 0;
}

