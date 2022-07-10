#include <stdio.h>
#include <math.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int years;
    long synallagma, orio;
    double rate;

    synallagma = (printf("Dwse to trexon touristiko synallagma: "), GetLong());
    rate = (printf("Dwse ton rythmo meiwshs: "), GetReal());
    orio = (printf("Dwse to orio: "), GetLong());

    years = 0;

    while (synallagma>=orio){
        years++;
        synallagma = ceil(synallagma*(1-rate));
    }

    printf("%d\n%ld",years,synallagma);

    return 0;
}

