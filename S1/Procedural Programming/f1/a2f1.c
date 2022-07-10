#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long x, y;
    double area;

    printf("Dose to mikos tis 1is kathetis plevras: ");
    x = GetLong();
    printf("Dose to mikos tis 2is kathetis plevras: ");
    y = GetLong();

    area = (x*y) / 2.0;
    printf("To emvado einai: %g", area);

    return 0;
}
