#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int meresErgasias;
    long imerisiaAmoivi;
    double rate, gift;

    printf("Dose tis imeres ergasias tou etous: ");
    meresErgasias = GetInteger();
    printf("Dose tin imerisia amoivi: ");
    imerisiaAmoivi = GetLong();
    printf("Dose to pososto dorou: ");
    rate = GetReal();

    gift = (meresErgasias*imerisiaAmoivi)*rate;
    printf("To doro einai: %g", gift);

    return 0;
}

