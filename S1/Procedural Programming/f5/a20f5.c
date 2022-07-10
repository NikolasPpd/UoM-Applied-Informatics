#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define ARRAY_SIZE 5

void shiftArrayElements(int array[]){

    int temp,i;
    temp = array[ARRAY_SIZE-1];

    for (i=ARRAY_SIZE-1;i>0;i--){
        array[i] = array[i-1];
    }
    array[0] = temp;
}

int main() {

    int numList[ARRAY_SIZE];
    int i;

    for (i=0;i<ARRAY_SIZE;i++){
        numList[i] = (printf("Enter number: "),GetInteger());
    }
    shiftArrayElements(numList);

    for (i=0;i<ARRAY_SIZE;i++){
        printf("%d ",numList[i]);
    }

    return 0;
}
