#include <stdio.h>

int mkd(int a, int b);

int main() {

    int N,i;

    printf("Enter N:");
    scanf("%d", &N);

    if (N<1 || N>999999999){
        printf("Wrong Input");
        return 0;
    }

    for (i=1;i<=N;i++){
        if (mkd(i,N) == 1){
            printf("%d ",i);
        }
    }
    return 0;
}

int mkd(int a, int b){

    if (b == 0) return a;
    return mkd(b,a%b);
}
