#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    double weight, height, DMS;

    height = (printf("Dose ypsos :"), GetReal());
    weight = (printf("Dose varos :"), GetReal());
    DMS = weight / (height*height);

    if (DMS < 18.5){
        printf("Lipovaris");
    }
    else if (DMS >= 18.5 && DMS < 25.0){
        printf("Kanonikos");
    }
    else if (DMS >= 25.0 && DMS <30.0){
        printf("Ypervaros");
    }
    else {
        printf("Paxysarkos");
    }
    return 0;
}
