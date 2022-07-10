#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    double miles,litres, lpm;

    miles = (printf("Dose milia kai litra :"), GetReal());
    litres = GetReal();

    lpm = litres/miles;

    if (lpm >= 0 && lpm <=0.9){
        printf("Poli xamili");
    }
    else if (lpm <= 1.2){
        printf("Xamili");
    }
    else if (lpm <= 1.8){
        printf("Kanoniki");
    }
    else if (lpm > 1.8){
        printf("Ypsili");
    }
    return 0;
}
