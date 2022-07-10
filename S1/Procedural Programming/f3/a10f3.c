#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int xNum, yNum;

    for (yNum=1; yNum<=10; yNum++){
        for (xNum=1; xNum<=10; xNum++){
            printf("%4d",yNum*xNum);
        }
        printf("\n");
    }

    return 0;
}
