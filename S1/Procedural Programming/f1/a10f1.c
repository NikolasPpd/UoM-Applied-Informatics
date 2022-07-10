#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>

int main() {

    int height, weight;

    printf("Dose to varos: ");
    weight = GetInteger();

    height = ceil((1.12*weight + 65)*1.2 + 7.0);
    printf("To ipsos einai: %d", height);

    return 0;
}
