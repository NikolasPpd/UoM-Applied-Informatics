#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int misthos, paidia;
    double epidoma;

    misthos = (printf("Dwse ton vasiko mistho: "), GetInteger());
    paidia = (printf("Dwse ton arithmo ton paidion: "), GetInteger());

    if (paidia == 1){
        epidoma = misthos*0.04;
    }
    else if (paidia == 2){
        epidoma = misthos*0.09;
    }
    else if (paidia == 3){
        epidoma = misthos*0.15;
    }
    else if (paidia > 3){
        epidoma = misthos*(0.15 + (paidia-3)*0.04);
    }
    printf("To epidoma einai %g", epidoma);

    return 0;
}
