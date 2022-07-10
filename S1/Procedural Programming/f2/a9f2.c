#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int productID, pieces, price;
    double discount, discountPrice, totalPrice;

    printf("Dwse ton kwdiko tou proiontos: ");
    productID = GetInteger();
    printf("Dwse ton arithmo twn temaxiwn: ");
    pieces = GetInteger();

    price = (productID / 100) + (productID % 100);

    if (pieces > 0 && pieces <31){
        discount = 0.1;
    }
    else if (pieces > 30 && pieces < 71){
        discount = 0.2;
    }
    else if (pieces > 70){
        discount = 0.35;
    }

    discountPrice = (price * pieces) * discount;
    totalPrice = (price * pieces) - discountPrice;

    printf ("H timh pwlhshs toy proiontos einai %d\n",price);
    printf ("H ekptwsh einai %g\n",discountPrice);
    printf ("H telikh timh ths paragelia einai %g\n",totalPrice);

    return 0;
}
