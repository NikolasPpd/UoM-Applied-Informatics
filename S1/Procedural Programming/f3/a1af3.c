#include <stdio.h>
#include <math.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long Arithmo_Aytok, Orio, eti;
    double Rythmos;

    Arithmo_Aytok = 80000;
    Orio = 160000;
    Rythmos = 0.07;
    eti = 0;

    while (Arithmo_Aytok <= Orio) {
        eti++;
        Arithmo_Aytok = ceil(Arithmo_Aytok*(1+Rythmos));
    }
    printf("%ld\n%d",eti,Arithmo_Aytok);

    return 0;
}
