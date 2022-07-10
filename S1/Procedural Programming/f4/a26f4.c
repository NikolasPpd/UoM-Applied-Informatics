#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int f(int x);
int g(int x, int y);

int main() {

    int x,y;

    x = (printf("Enter x: "), GetInteger());
    y = (printf("Enter y: "), GetInteger());

    printf("f(x) = f(%d) = %d\n",x,f(x));
    printf("g(x,y) = g(%d,%d) = %d\n",x,y,g(x,y));
    printf("f(g(x,y)) = f(g(%d,%d)) = %d\n",x,y,f(g(x,y)));

    return 0;
}

int f(int x){

    if (x>0){
        return (x+2);
    }
    return (-3*x+7);
}

int g(int x, int y){

    if (x>0 && y>0){
        return (x-y);
    }
    return (7*x-5);
}
