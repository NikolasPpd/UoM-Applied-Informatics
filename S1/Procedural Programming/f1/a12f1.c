#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long katharaTM, miktaTM;
    double dimTeli, dimForos;

    printf("Dose ta kathara tm tou spitiou: ");
    katharaTM = GetLong();
    printf("Dose ta mikta tm tou spitiou: ");
    miktaTM = GetLong();

    dimTeli = katharaTM * 1.33 * 61 / 365;
    dimForos = miktaTM * 0.13 * 61 / 365;

    printf("Ta DT einai: %.2f", dimTeli);
    printf("\nO DF einai: %.2f", dimForos);

    return 0;
}
