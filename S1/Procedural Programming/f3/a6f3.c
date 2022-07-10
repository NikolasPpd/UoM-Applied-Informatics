#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main() {

    int N, i, n1, n2, tempSum;

    n1 = 0;
    n2 = 1;
    N = GetInteger();

    if (N == 1){
        printf("0\n");
    }
    else if (N == 2){
        printf("0\n1\n");
    }
    else if (N > 2){
        printf("0\n1\n");
        for (i=3; i <= N; i++) {
            tempSum = n1 + n2;
            printf("%d\n",tempSum);
            n1 = n2;
            n2 = tempSum;
        }
    }
    return 0;
}
