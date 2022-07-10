#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int Sum_Cube (int NUM);
bool IsArmstrong(int NUM);
int Cube(int NUM);

int main() {

    int i;

    for (i=1; i<1000; i++){
        if (IsArmstrong(i)){
            printf("%d\n",i);
        }
    }
    return 0;
}

// Sum the cube of every digit of the given number
int Sum_Cube (int NUM){

    int sum=0;

    while (NUM > 0){
        sum += Cube(NUM%10);
        NUM /= 10;
    }
    return sum;
}

// Check if the given number is an Armstrong number or not
bool IsArmstrong (int NUM){

    return (Sum_Cube(NUM)==NUM?TRUE:FALSE);
}

// Calculate the cube of a given number
int Cube(int NUM){

    int i,product=1;

    for (i=0;i<3;i++){
        product*=NUM;
    }
    return product;
}
