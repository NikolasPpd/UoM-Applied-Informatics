#include <stdio.h>
#include <math.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long Arithmo_Aytok, Orio, eti;
    double Rythmos;

    //Eisagogi timon apo ton xrhsth
    Arithmo_Aytok = (printf("Dwse ton arxiko arithmo autokinhtwn: "), GetLong());
    Rythmos = (printf("Dwse ton ethsio rythmo ayxhshs: "), GetReal());
    Orio = (printf("Dwse to orio: "), GetLong());

    //arxikopoihsh metavlitis "eti"
    eti = 0;

    while (Arithmo_Aytok <= Orio) {
        eti++;
        Arithmo_Aytok = ceil(Arithmo_Aytok*(1+Rythmos));
    }
    printf("%ld\n%ld",eti,Arithmo_Aytok);

    return 0;
}
