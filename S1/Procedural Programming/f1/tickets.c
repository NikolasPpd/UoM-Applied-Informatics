#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int tickets, c200, c100, c50, c20, c10, c5, c1, pennies;
    double cash, change;

    printf("Dose aritho eisitirion kai lefta: ");
    tickets = GetInteger();
    cash = GetReal();

    pennies = cash*100;
    change = pennies - tickets*75;

    c200 = change / 200;
    change -= c200*200;
    c100 = change / 100;
    change -= c100*100;
    c50 = change / 50;
    change -= c50*50;
    c20 = change / 20;
    change -= c20*20;
    c10 = change / 10;
    change -= c10*10;
    c5 = change / 5;
    change -= c5*5;
    c1 = change / 1;

    printf("2:\t%d\n1:\t%d\n0.50:\t%d\n0.20:\t%d\n0.10:\t%d\n0.05:\t%d\n0.01:\t%d", c200, c100, c50, c20, c10, c5, c1);

    return 0;
}

