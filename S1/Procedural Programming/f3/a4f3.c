#include <stdio.h>
#include <math.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    //dilosi metavliton
    int code, atoma;
    long cost, revenue, profit;

    //arxikopoiisi metavliton
    revenue = profit = 0;

    //ypologismos timon
    while (TRUE){
        code = (printf("Dwse ton kwdiko: "), GetInteger());
        if (code == 2) break;
        if (code == 1){
            atoma = (printf("Dwse ton arithmo twn atomwn: "), GetInteger());
            cost = (atoma <= 10 ? (atoma*350) : ceil(atoma*350*0.9));
            revenue += cost;
            printf("Kostos krathshs: %ld\n", cost);
        }
        else {
            printf("Lathos Kwdikos.\n");
        }
    }

    profit = revenue - 20000;
    printf("Kerdos h zhmia (-) gia to taxidi: %ld\n",profit);

    return 0;
}
