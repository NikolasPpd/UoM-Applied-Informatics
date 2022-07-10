#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int gcd(int a, int b);
bool areCoprime(int a, int b);
int phi(int num);

int main() {

    int x,i;

    x = (printf("Enter X:"),GetInteger());

    for (i=1;i<=x;i++){
        printf("phi(%d) = %d\n",i,phi(i));
    }
    return 0;
}

int gcd(int a, int b){

    if (b == 0) return a;
    return gcd(b,a%b);
}

bool areCoprime(int a, int b){

    if (gcd(a,b) == 1) return TRUE;
    return FALSE;
}

int phi(int num){

    int i, count=0;

    for (i=1;i<=num;i++){
        if (areCoprime(i,num)) count++;
    }
    return count;
}
