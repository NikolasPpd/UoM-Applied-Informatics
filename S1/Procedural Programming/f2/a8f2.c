#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int expectedTime, actualTime, acceptableDiff, diff, minDiff, maxDiff;

    printf("Dwse ton problepomeno xrono: ");
    expectedTime = GetInteger();
    printf("Dwse ton pragmatiko xrono: ");
    actualTime = GetInteger();

    if (expectedTime >= 0 && expectedTime < 30){
        acceptableDiff = 1;
    }
    else if (expectedTime < 60){
        acceptableDiff = 2;
    }
    else if (expectedTime < 90){
        acceptableDiff = 3;
    }
    else if (expectedTime < 120){
        acceptableDiff = 4;
    }
    else if (expectedTime < 180){
        acceptableDiff = 6;
    }
    else if (expectedTime < 240){
        acceptableDiff = 8;
    }
    else if (expectedTime < 360){
        acceptableDiff = 13;
    }
    else if (expectedTime > 359){
        acceptableDiff = 17;
    }

    printf("Apodekth diafora %d\n",acceptableDiff);
    diff = expectedTime-actualTime;
    printf("Diafora eisagomenwn timwn %d\n",diff);

    minDiff = expectedTime - acceptableDiff;
    maxDiff = expectedTime + acceptableDiff;

    if (actualTime < minDiff){
        printf("BIG\n");
    }
    else if (actualTime > maxDiff){
        printf("SMALL\n");
    }
    else{
        printf("GOOD\n");
    }
    return 0;
}
