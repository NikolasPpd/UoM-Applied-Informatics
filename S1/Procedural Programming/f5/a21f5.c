#include <stdio.h>
#include <math.h>
#include "simpio.h"
#include "genlib.h"

#define ARRAY_SIZE 5 // ARRAY_SIZE > 1

int main() {

    double numbers[ARRAY_SIZE];
    double distance[ARRAY_SIZE-1];
    int i;

    for (i=0;i<ARRAY_SIZE;i++){
        printf("Enter number (%d):",i) ;
        numbers[i] = GetReal();
    }

    for (i=0;i<ARRAY_SIZE-1;i++){
        distance[i] = fabs(numbers[i]-numbers[i+1]);
    }

    for (i=0;i<ARRAY_SIZE;i++){
        printf("%.2f ",numbers[i]);
    }
    printf("\n");
    for (i=0;i<ARRAY_SIZE-1;i++){
        printf("%.2f ",distance[i]);
    }
    return 0;
}
