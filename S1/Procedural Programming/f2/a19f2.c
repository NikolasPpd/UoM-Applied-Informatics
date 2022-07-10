#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int gramCO2;
    float teliKykloforias;

    printf("Dwse gram CO2/khm: ");
    gramCO2 = GetInteger();

    if ((gramCO2 >= 0) && (gramCO2 < 121)){
        teliKykloforias = 0.9*gramCO2;
    }
    else if ((gramCO2 > 120) && (gramCO2 < 141)){
        teliKykloforias = 1.1*gramCO2;
    }
    else if (gramCO2 > 140){
        teliKykloforias = 1.7*gramCO2;
    }

    printf("To poso pliromis einai: %g\n", teliKykloforias);

    return 0;
}

