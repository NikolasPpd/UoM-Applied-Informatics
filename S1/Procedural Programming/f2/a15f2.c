#include <stdio.h>
#include <math.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    double a,b,c,D,x1,x2;

    printf("Dose toys syntelestes a b & c :");
    a = GetReal();
    b = GetReal();
    c = GetReal();

    if (a == 0){
        printf ("H riza ths eksisoshs einai h x=%g", -c/b);
    }
    else {
        D = b*b -4*a*c;
        if (D > 0){
            x1 = (-b + sqrt(D)) / (2*a);
            x2 = (-b - sqrt(D)) / (2*a);
            printf("Oi rizes ths eksisoshs einai x1=%g kai x2=%g",x1,x2);
        }
        else if (D < 0){
            printf("Den exei pragmatikes rizes");
        }
        else {
            printf("H eksisosh exei mia diplh riza thn x=%g", -b/(2*a));
        }
    }
    return 0;
}
