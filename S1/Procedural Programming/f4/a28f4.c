#include <stdio.h>
#include <math.h>
#include "simpio.h"
//#include "genlib.h"

int get_code();
double discount_percentage(int code);
int product_points(int code, double price);

int main() {

    int code, points=0;
    double price, total=0, discount=0;

    while (TRUE){
        code = get_code();
        if (code == 0) break;
        price = (printf("Dwse thn timh: "), GetReal());
        total += price*(1-discount_percentage(code));
        discount += price*discount_percentage(code);
        points += product_points(code,price);
    }
    printf("------------------\n");
    printf("Teliko synolo: %.2f Euro\n",total);
    printf("Ekptwsh: %.2f Euro\n",discount);
    printf("Pontoi: %d\n",points);
    return 0;
}

int get_code(){

    int code;

    do {
        code = (printf("Dwse ton kwdiko: "),GetInteger());
        if (code<0 || code>2000) printf("Lathos Kwdikos (0-2000)\n");
    } while (code<0 || code>2000);
    return code;
}

double discount_percentage(int code){

    if (code <=300) return 0.05;
    else if (code <= 500) return 0.1;
    else if (code <= 1000) return 0.15;
    else return 0.2;
}

int product_points(int code, double price){

    return (1 + (code>=1000 && code<=1500? ceil(price*(1-discount_percentage(code))/5) : 0));
}
