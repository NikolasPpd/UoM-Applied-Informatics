#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int seats, passengers;
    double percentage;

    seats = (printf("Dose theseis :"), GetInteger());
    passengers = (printf("Dose epibates :"), GetInteger());
    percentage = ((double)passengers/seats)*100;

    if (percentage >= 50){
        printf("Stonks");
    }
    else if (percentage < 30){
        printf("Not stonks");
    }
    else {
        printf("Kostos");
    }
    return 0;
}
