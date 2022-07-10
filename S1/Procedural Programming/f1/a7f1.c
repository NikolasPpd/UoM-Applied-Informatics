#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long fpa4, fpa8, fpa18;
    double totalFpa;

    printf("Dose tis sinolikes eisprakseis gia FPA 0.04: ");
    fpa4 = GetLong();
    printf("Dose tis sinolikes eisprakseis gia FPA 0.08: ");
    fpa8 = GetLong();
    printf("Dose tis sinolikes eisprakseis gia FPA 0.18: ");
    fpa18 = GetLong();

    totalFpa = 0.04*fpa4 + 0.08*fpa8 + 0.18*fpa18;

    printf("To sinoliko poso FPA einai: %g", totalFpa);

    return 0;
}
