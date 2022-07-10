#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long lettersHome, lettersOverseas;
    double cost;

    printf("Dose ton aritho epistolon esoterikou: ");
    lettersHome = GetLong();
    printf("Dose ton aritho epistolon eksoterikou: ");
    lettersOverseas = GetLong();

    cost = lettersHome*0.3 + lettersOverseas*0.8;
    printf("To sinoliko kostos apostolis einai: %g", cost);

    return 0;
}
