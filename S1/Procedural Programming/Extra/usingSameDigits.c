#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int num1,num2,i;
    int num1Digits[]={0,0,0,0,0,0,0,0,0,0};
    int num2Digits[]={0,0,0,0,0,0,0,0,0,0};

    num1 = (printf("Number 1: "),GetInteger());
    num2 = (printf("Number 2: "),GetInteger());

    while (num1!=0){
        num1Digits[num1%10] = 1;
        num1/=10;
    }
    while (num2!=0){
        num2Digits[num2%10] = 1;
        num2/=10;
    }

    for (i=0;i<10;i++){
        if (num1Digits[i] != num2Digits[i]){
            printf("The numbers you entered don't use the same exact digits.\n");
            return 0;
        }
    }
    printf("The numbers you entered consist of the same digits.\n");
    return 0;
}
