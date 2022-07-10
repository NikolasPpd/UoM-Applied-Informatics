#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define CITIES 10
#define DAY_PARTS 3

double absValue(double num){
    if (num < 0) return (-num);
    return num;
}

int main() {

    double temperatures[CITIES][DAY_PARTS];
    int i,j;
    double natSum=0,natAverage,citySum,cityAverage,deviance;

    for (i=0;i<CITIES;i++){
        for (j=0;j<DAY_PARTS;j++){
            printf("Temp of City %d During %d %d-hour period: ",i,j,24/DAY_PARTS);
            temperatures[i][j] = GetReal();
            natSum += temperatures[i][j];
        }
    }
    natAverage = natSum/(CITIES*DAY_PARTS);
    printf("%.1f\n",natAverage);

    for (i=0;i<CITIES;i++){
        citySum=0;
        deviance=0;
        for (j=0;j<DAY_PARTS;j++){
            citySum += temperatures[i][j];
        }
        cityAverage = citySum/DAY_PARTS;
        for (j=0;j<DAY_PARTS;j++){
            if (absValue(natAverage-temperatures[i][j]) > deviance){
                deviance = absValue(natAverage-temperatures[i][j]);
            }
        }
        printf("City %d  %.1f  %.1f\n",i,cityAverage,deviance);
    }
    return 0;
}
