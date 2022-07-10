#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int vathmos, plithos, sinolo;
    double MO;

    plithos = sinolo = 0;

    while (TRUE){
        vathmos = (printf("Dwse ton bathmo: "), GetInteger());
        if (vathmos == -1) break;
        plithos++;
        sinolo += vathmos;
    }

    if (plithos == 0){
        MO = 0;
    }
    else {
        MO = (double)sinolo / plithos;
    }

    printf("%d\n%d\n%g",plithos,sinolo,MO);

    return 0;
}
