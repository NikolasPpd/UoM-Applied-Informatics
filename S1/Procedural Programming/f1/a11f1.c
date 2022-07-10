#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    long timiTem, plithosTem;
    double FPA, kostos;

    printf("Dose tin timi temaxiou: ");
    timiTem = GetLong();
    printf("Dose to pososto FPA: ");
    FPA = GetReal();
    printf("Dose to plithos ton temaxion: ");
    plithosTem = GetReal();

    kostos = timiTem*plithosTem*(1.0 + FPA);

    printf("To kostos tis paraggelias einai: %g", kostos);

    return 0;
}
