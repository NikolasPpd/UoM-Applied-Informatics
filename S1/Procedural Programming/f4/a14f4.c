#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int max(int a, int b);
int gr(int a, int b, int c);

int main() {

    int a,b,c;
    double y;

    a = (printf("Dwse a: "),GetInteger());
    b = (printf("Dwse b: "),GetInteger());
    c = (printf("Dwse c: "),GetInteger());

    y = (2*max(a,b)+3*gr(a,b,c))/4.0;

    printf("y = %.2f",y);
    return 0;
}

int max(int a, int b){

    if (a>b) return a;
    return b;
}

int gr(int a, int b, int c){

    if (a>=b && a>=c) return a;
    else if (b>=a && b>=c) return b;
    return c;
}
