#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    //dilosi metavliton
    int i, num;
    float total;

    //arxikopoiisi metavliton
    total = 0;

    //eisagogi timis apo user
    num = (printf("Dwse orio:"), GetInteger());

    //ypologismos athroismatos
    for (i=1; i<=num; i++){
        total = total + (1/(float)i);
    }

    //emfanisi apotelesmaton
    printf("To athroisma einai %.2f", total);

    return 0;
}
