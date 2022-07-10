#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int kafedes, c10, c20, c50, c100, c200, cost, change;

    printf("Dose kafedes: ");
    kafedes = GetInteger();
    cost = kafedes*70;

    if (cost>500){
        printf("Den ftanoun ta xrhmata gia tosous kafedes.\n");
    }
    else {
        change = 500 - cost;
        c200 = change / 200;
        change -= c200*200;
        c100 = change / 100;
        change -= c100*100;
        c50 = change / 50;
        change -= c50*50;
        c20 = change / 20;
        change -= c20*20;
        c10 = change / 10;

        printf("Resta\nKermata 2E :%d\nKermata 1E :%d\nKermata 50L :%d\nKermata 20L :%d\nKermata 10L :%d\n",c200,c100,c50,c20,c10);
    }
    return 0;
}
