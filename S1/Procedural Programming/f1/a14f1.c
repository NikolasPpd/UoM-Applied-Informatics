#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int height, age, weight;
    double BMR;

    printf("Dwse varos se kila: ");
    weight = GetInteger();
    printf("Dwse upsos se cm: ");
    height = GetInteger();
    printf("Dwse ilikia se xronia: ");
    age = GetInteger();

    BMR = 655 + (9.6*weight) + (1.8*height) - (4.7*age);

    printf("To BMR einai %g\n", BMR);

    return 0;

}
