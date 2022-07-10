#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int num,i;

    num = (printf("Enter number: "),GetInteger());

    if ((num%2)==0){ //artios
        for (i=0;i<=num;i+=2){
            printf("%d ",i);
        }
    }
    else {
        for (i=1;i<=num;i+=2){
            printf("%d ",i);
        }
    }
    return 0;
}

