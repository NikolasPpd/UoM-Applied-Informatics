#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int SMS;
    double cost;

    SMS = (printf("Dose plithos sms :"), GetInteger());

    //ypologismos kostous
    if (SMS > 10){
        cost = 20;
        if (SMS > 60){
            cost += 75;
            if (SMS > 160){
                cost += 120;
                cost += SMS - 160;
            }
            else {
                cost += (SMS - 60)*1.2;
            }
        }
        else {
            cost += (SMS-10)*1.5;
        }
    }
    else {
        cost = SMS*2;
    }

    printf("Synoliko poso se euro: %g", cost/100);

    return 0;
}
